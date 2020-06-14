#include "SmallEnemy.h"

#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "TowerDefenseGameState.h"

ASmallEnemy::ASmallEnemy()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMesh(TEXT("/Game/Geometry/Meshes/SmallEnemy.SmallEnemy"));

	auto Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	Mesh->SetStaticMesh(EnemyMesh.Object);
	RootComponent = Mesh;

	SetActorScale3D(FVector(0.6f, 0.6f, 0.6f));
}

