#include "ArrowTower.h"

#include "EngineUtils.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "TowerDefenseGameState.h"
#include "EnemyBase.h"
#include "ArrowProjectile.h"

AArrowTower::AArrowTower()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ArrowTowerMesh(TEXT("/Game/Geometry/Meshes/ArrowTower.ArrowTower"));

	auto Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerMesh"));
	Mesh->SetStaticMesh(ArrowTowerMesh.Object);
	RootComponent = Mesh;

	Name = TEXT("Arrow Tower");
	Level = 1;
	Health = HealthArr[Level];
	Attack = AttackArr[Level];
	Speed = SpeedArr[Level];
	Range = RangeArr[Level];
	Cost = CostArr[Level];
}

void AArrowTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Timer <= 0) {
		// 搜索范围内的敌人
		for (TActorIterator<AEnemyBase> It(GetWorld()); It; ++It) {
			FVector StartP = GetActorLocation() + FVector(0, 0, 130.f);
			FVector Dir = It->GetActorLocation() - StartP;
			if (Dir.Size2D() <= Range) {
				// 发射子弹
				auto Projectile = GetWorld()->SpawnActor<AArrowProjectile>(StartP, Dir.GetSafeNormal().Rotation());
				Projectile->Init(Attack);
				Timer += 5.0f / Speed;
				break;
			}
		}
	}
	else Timer -= DeltaTime;
}

void AArrowTower::Upgrade()
{
	GetWorld()->GetGameState<ATowerDefenseGameState>()->Cost(Cost);
	Level++;
	Health = HealthArr[Level];
	Attack = AttackArr[Level];
	Speed = SpeedArr[Level];
	Range = RangeArr[Level];
	Cost = CostArr[Level];
}
