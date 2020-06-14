#include "BombTower.h"

#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "TowerDefenseGameState.h"

ABombTower::ABombTower()
{
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

void ABombTower::Upgrade()
{
	GetWorld()->GetGameState<ATowerDefenseGameState>()->Money -= Cost;
	Level++;
	Health = HealthArr[Level];
	Attack = AttackArr[Level];
	Speed = SpeedArr[Level];
	Range = RangeArr[Level];
	Cost = CostArr[Level];
}

