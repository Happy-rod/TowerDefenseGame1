// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <functional>

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuildDialogUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSETEST_API UBuildDialogUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void OnButtonArrowTower();

	UFUNCTION(BlueprintCallable)
		void OnButtonBombTower();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bCanBuildArrowTower = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bCanBuildBombTower = false;

	std::function<void()> BuildArrowTowerDelegate;
	std::function<void()> BuildBombTowerDelegate;

	void Init(std::function<void()> buildArrowTowerDelegate, std::function<void()> buildBombTowerDelegate, bool canBuildArrowTower, bool canBuildBombTower);
};
