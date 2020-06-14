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

	int Health = 15;
	int Money = 10;

private:

	float Timer = 0;

	UUserWidget* PlayerInfoWidgetInstance = nullptr;

};
