// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "BigEnemy.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSETEST_API ABigEnemy : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	ABigEnemy();

	virtual void Tick(float DeltaTime) override;

private:
	float Timer = 0;


public:

	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
		class USoundBase* FireSound;
};
