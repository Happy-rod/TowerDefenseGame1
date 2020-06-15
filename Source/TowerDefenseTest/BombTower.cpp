#include "BombTower.h"

#include "EngineUtils.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "TowerDefenseGameState.h"
#include "EnemyBase.h"
#include "BombProjectile.h"

ABombTower::ABombTower()
{
	// Sound
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BombTowerMesh(TEXT("/Game/Geometry/Meshes/BombTower.BombTower"));

	auto Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerMesh"));
	Mesh->SetStaticMesh(BombTowerMesh.Object);
	RootComponent = Mesh;

	Name = TEXT("Bomb Tower");
	Level = 1;
	Health = HealthArr[Level];
	Attack = AttackArr[Level];
	Speed = SpeedArr[Level];
	Range = RangeArr[Level];
	Cost = CostArr[Level];
}

void ABombTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Timer <= 0) {
		for (TActorIterator<AEnemyBase> It(GetWorld()); It; ++It) {
			FVector StartP = GetActorLocation();
			FVector Dir = It->GetActorLocation() - StartP;
			if (Dir.Size2D() <= Range) {
				// ·¢ÉäÕ¨µ¯
				auto Projectile = GetWorld()->SpawnActor<ABombProjectile>(StartP, Dir.GetSafeNormal().Rotation());
				// ÒôÐ§
				if (FireSound != nullptr) {
					UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
				}
				Projectile->Init(Range, Attack);
				Timer += 5.0f / Speed;
				break;
			}
		}
	}
	else Timer -= DeltaTime;
}

void ABombTower::Upgrade()
{
	GetWorld()->GetGameState<ATowerDefenseGameState>()->Cost(this->Cost);
	Level++;
	Health = HealthArr[Level];
	Attack = AttackArr[Level];
	Speed = SpeedArr[Level];
	Range = RangeArr[Level];
	Cost = CostArr[Level];
}

