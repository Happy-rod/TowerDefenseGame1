#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBase.generated.h"

UCLASS()
class TOWERDEFENSETEST_API AEnemyBase : public AActor
{
	GENERATED_BODY()

public:	
	AEnemyBase();

private:
	int32 XArr[6] = { -470, -450, -180, -160, 130, 130 };
	int32 YArr[6] = { -130, 300, 300, 10, 20, 430 };
	int32 CurStage = 0;
	FVector PreLocation;

protected:
	virtual void BeginPlay() override;

	int32 Health = 15;
	int32 Speed = 60;
	int32 Damage = 1;
	int32 Bonus = 1;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser);
};
