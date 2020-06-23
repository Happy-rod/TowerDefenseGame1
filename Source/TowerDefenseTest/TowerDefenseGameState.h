// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TowerDefenseGameState.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSETEST_API ATowerDefenseGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ATowerDefenseGameState();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void Damage(int Damage);
	void Cost(int Cost);
	void Win();

	int Health = 15;
	int Money = 50;

private:

	float Timer = 0;

	bool bCanWin = false;

	UUserWidget* PlayerInfoWidgetInstance = nullptr;

	UUserWidget* GameResultWidgetInstance = nullptr;

};
