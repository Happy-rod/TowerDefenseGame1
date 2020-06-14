#include "ArrowTower.h"

#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "TowerDefenseGameState.h"

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
