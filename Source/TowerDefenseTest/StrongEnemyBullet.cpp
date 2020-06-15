#include "StrongEnemyBullet.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "TowerBase.h"

AStrongEnemyBullet::AStrongEnemyBullet()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AStrongEnemyBullet::OnHit);
	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 500.f;
	ProjectileMovement->MaxSpeed = 500.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f;

	InitialLifeSpan = 1.5f;
}

void AStrongEnemyBullet::Init(int Dmg)
{
	Damage = Dmg;
}

void AStrongEnemyBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

void AStrongEnemyBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStrongEnemyBullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherActor->GetClass()->IsChildOf(ATowerBase::StaticClass()))
	{
		OtherActor->TakeDamage(Damage, FDamageEvent(), NULL, NULL);
	}
	Destroy();
}
