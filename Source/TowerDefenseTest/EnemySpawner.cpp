#include "EnemySpawner.h"

#include "TowerDefenseGameState.h"
#include "SmallEnemy.h"
#include "StrongEnemy.h"
#include "BigEnemy.h"

AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (NextEnemyIt == sizeof(EnemySeq) / sizeof(char)) {
		// Ê¤Àû
		GetWorld()->GetGameState<ATowerDefenseGameState>()->Win();
		Destroy();
	}
	else if (Timer <= 0) {
		Timer = 1;
		char NextEnemySign = EnemySeq[NextEnemyIt++];
		switch (NextEnemySign) {
		case 'a':
			GetWorld()->SpawnActor<ASmallEnemy>();
			break;
		case 'b':
			GetWorld()->SpawnActor<AStrongEnemy>();
			break;
		case 'c':
			GetWorld()->SpawnActor<ABigEnemy>();
			break;
		}
	}
	else Timer -= DeltaTime;
}
