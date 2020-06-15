#include "BombProjectile.h"

#include "EngineUtils.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "EnemyBase.h"

ABombProjectile::ABombProjectile()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/Geometry/Meshes/BombBullet.BombBullet"));

	auto ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	RootComponent = ProjectileMesh;

	InitialLifeSpan = 0.5f;

	SetActorScale3D(FVector(1.8f, 1.8f, 1.8f));
}

void ABombProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ABombProjectile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for (TActorIterator<AEnemyBase> It(GetWorld()); It; ++It) {
		FVector StartP = GetActorLocation();
		FVector Dir = It->GetActorLocation() - StartP;
		if (Dir.Size2D() <= Range) {
			It->TakeDamage(Damage, FDamageEvent(), NULL, NULL);
		}
	}
}

void ABombProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABombProjectile::Init(int32 Rng, int32 Dmg)
{
	Range = Rng;
	Damage = Dmg;
}
