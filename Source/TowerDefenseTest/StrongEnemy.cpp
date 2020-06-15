#include "StrongEnemy.h"

#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "TowerDefenseGameState.h"

AStrongEnemy::AStrongEnemy()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMesh(TEXT("/Game/Geometry/Meshes/StrongEnemy.StrongEnemy"));

	auto Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	Mesh->SetStaticMesh(EnemyMesh.Object);
	RootComponent = Mesh;

	SetActorScale3D(FVector(1.1f, 1.1f, 0.3f));

	Health = 20;
	Speed = 50;
}
