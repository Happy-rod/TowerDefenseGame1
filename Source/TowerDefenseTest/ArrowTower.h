#pragma once

#include "CoreMinimal.h"
#include "TowerBase.h"
#include "ArrowTower.generated.h"

class USoundBase;

UCLASS()
class TOWERDEFENSETEST_API AArrowTower : public ATowerBase
{
	GENERATED_BODY()

private:
	int32 HealthArr[8] = { 0, 200, 250, 350, 500, 700, 1000 };
	int32 AttackArr[8] = { 0, 2, 3, 5, 8, 13, 233 };
	int32 SpeedArr[8] = { 0, 5, 5, 6, 6, 7, 9 };
	int32 RangeArr[8] = { 0, 150, 200, 250, 300, 350, 500 };
	int32 CostArr[8] = { 0, 10, 12, 15, 18, 22, 10000000 };

	float Timer = 0;

public:

	AArrowTower();

	virtual void Tick(float DeltaTime) override;

	virtual void Upgrade() override;

	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
		USoundBase* FireSound;
};
