#pragma once

#include <functional>

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UpgradeDialogUserWidget.generated.h"

UCLASS()
class TOWERDEFENSETEST_API UUpgradeDialogUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void OnButtonUpgrade();

	UFUNCTION(BlueprintCallable)
		void OnButtonDestroy();

	void Init(std::function<void()> upgradeDelegate, std::function<void()> destoryDelegate, FString name, int32 level, int32 health, int32 attack, int32 speed, int32 range, int32 cost, bool canUpgrade);

	std::function<void()> UpgradeDelegate;

	std::function<void()> DestroyDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString TowerName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Attack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Range;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Cost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bCanUpgrade;


};
