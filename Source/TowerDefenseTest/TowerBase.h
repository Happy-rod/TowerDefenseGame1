#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerBase.generated.h"

class UUserWidget;

UCLASS()
class TOWERDEFENSETEST_API ATowerBase : public AActor
{
	GENERATED_BODY()
	
public:
	ATowerBase();

protected:
	FString Name;
	int32 Level;
	int32 Health;
	int32 Attack;
	int32 Speed;
	int32 Range;
	int32 Cost;

protected:
	virtual void BeginPlay() override;
	virtual void Upgrade();
	void DestroyTower();

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnClick(AActor* TouchedActor, FKey ButtonPressed);

private:
	UUserWidget* UpgradeDialogInstance = nullptr;

};
