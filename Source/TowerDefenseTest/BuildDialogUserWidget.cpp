// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildDialogUserWidget.h"

void UBuildDialogUserWidget::OnButtonArrowTower()
{
	BuildArrowTowerDelegate();
}

void UBuildDialogUserWidget::OnButtonBombTower()
{
	BuildBombTowerDelegate();
}

void UBuildDialogUserWidget::Init(std::function<void()> buildArrowTowerDelegate, std::function<void()> buildBombTowerDelegate, bool canBuildArrowTower, bool canBuildBombTower)
{
	BuildArrowTowerDelegate = buildArrowTowerDelegate;
	BuildBombTowerDelegate = buildBombTowerDelegate;
	bCanBuildArrowTower = canBuildArrowTower;
	bCanBuildBombTower = canBuildBombTower;
}