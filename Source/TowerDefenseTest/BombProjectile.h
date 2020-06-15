#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BombProjectile.generated.h"

UCLASS()
class TOWERDEFENSETEST_API ABombProjectile : public AActor
{
	GENERATED_BODY()

private:
	int32 Range = 0;
	int32 Damage = 0;
	
public:
	ABombProjectile();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

	void Init(int32 Rng, int32 Dmg);
};
