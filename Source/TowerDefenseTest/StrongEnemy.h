#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "StrongEnemy.generated.h"

UCLASS()
class TOWERDEFENSETEST_API AStrongEnemy : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	AStrongEnemy();

	virtual void Tick(float DeltaTime) override;

private:
	float Timer;

public:

	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
		class USoundBase* FireSound;

};
