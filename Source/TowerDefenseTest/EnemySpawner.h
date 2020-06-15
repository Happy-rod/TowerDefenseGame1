#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TOWERDEFENSETEST_API AEnemySpawner : public AActor
{
	GENERATED_BODY()

private:
	float Timer = 3;
	char EnemySeq[32] = { 'a', 'a', 'a', 'a', 0, 0, 0, 0, 'b', 'b', 0, 0, 0, 0, 'a', 'a', 'c', 0, 0, 0, 0, 0, 0, 'a', 'a', 'b', 'a', 'a', 'b', 'c', 'a', 'a' };
	int32 NextEnemyIt = 0;
	
public:
	AEnemySpawner();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
