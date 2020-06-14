// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerInfoUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSETEST_API UPlayerInfoUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Money;
};
