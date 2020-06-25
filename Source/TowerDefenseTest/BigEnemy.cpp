#include "BigEnemy.h"

#include "EngineUtils.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "TowerDefenseGameState.h"
#include "TowerBase.h"
#include "StrongEnemyBullet.h"

ABigEnemy::ABigEnemy()
{
	// Sound
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMesh(TEXT("/Game/Geometry/Meshes/BigEnemy.BigEnemy"));

	auto Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	Mesh->SetStaticMesh(EnemyMesh.Object);
	RootComponent = Mesh;

	SetActorScale3D(FVector(1.4f, 1.4f, 1.4f));

	Health = 50;
	Speed = 60;
	Damage = 3;
	Bonus = 10;
}

void ABigEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Timer <= 0) {
		// ËÑË÷·¶Î§ÄÚµÄ·ÀÓùËþ
		for (TActorIterator<ATowerBase> It(GetWorld()); It; ++It) {
			FVector StartP = GetActorLocation() + FVector(0, 0, 130.f);
			FVector Dir = It->GetActorLocation() - StartP;
			if (Dir.Size2D() <= 200) {
				// ·¢Éä×Óµ¯
				auto Projectile = GetWorld()->SpawnActor<AStrongEnemyBullet>(StartP, Dir.GetSafeNormal().Rotation());
				// ÒôÐ§
				if (FireSound != nullptr) {
					UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
				}
				Projectile->Init(10);
				Timer = 0.3;
				break;
			}
		}
	}
	else Timer -= DeltaTime;
}