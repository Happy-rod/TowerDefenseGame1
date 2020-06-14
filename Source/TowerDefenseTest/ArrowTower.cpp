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

	UE_LOG(LogTemp, Warning, TEXT("CNM"));
	if (Timer <= 0) {
		// 搜索范围内的敌人
		for (TActorIterator<AEnemyBase> It(GetWorld()); It; ++It) {
			FVector Dir = It->GetActorLocation() - GetActorLocation();
			UE_LOG(LogTemp, Warning, TEXT("Cnm %s"), *It->GetName());
			if (Dir.Size() <= Range * 100) {
				// 发射子弹
				GetWorld()->SpawnActor<AArrowProjectile>(GetActorLocation(), Dir.GetSafeNormal().Rotation());
				break;
			}
		}
	}
}

void AArrowTower::Upgrade()
{
	GetWorld()->GetGameState<ATowerDefenseGameState>()->Money -= Cost;
	Level++;
	Health = HealthArr[Level];
	Attack = AttackArr[Level];
	Speed = SpeedArr[Level];
	Range = RangeArr[Level];
	Cost = CostArr[Level];
}
