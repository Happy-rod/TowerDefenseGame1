#pragma once

#include "CoreMinimal.h"
#include "TowerBase.h"
#include "BombTower.generated.h"

UCLASS()
class TOWERDEFENSETEST_API ABombTower : public ATowerBase
{
	GENERATED_BODY()

private:
	int32 HealthArr[8] = { 0, 180, 220, 300, 400, 500, 800 };
	int32 AttackArr[8] = { 0, 4, 6, 8, 12, 18, 40 };
	int32 SpeedArr[8] = { 0, 2, 2, 3, 3, 4, 6 };
	int32 RangeArr[8] = { 0, 200, 220, 240, 270, 300, 400 };
	int32 CostArr[8] = { 0, 10, 12, 15, 18, 22, 10000000 };

	float Timer = 0;
	
public:

	ABombTower();

	virtual void Tick(float DeltaTime) override;

	virtual void Upgrade() override;
};
