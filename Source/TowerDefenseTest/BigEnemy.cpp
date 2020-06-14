#include "BigEnemy.h"

#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "TowerDefenseGameState.h"

ABigEnemy::ABigEnemy()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMesh(TEXT("/Game/Geometry/Meshes/BigEnemy.BigEnemy"));

	auto Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	Mesh->SetStaticMesh(EnemyMesh.Object);
	RootComponent = Mesh;

	SetActorScale3D(FVector(1.4f, 1.4f, 1.4f));

	Speed = 60;
}
