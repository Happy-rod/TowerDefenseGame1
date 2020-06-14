#include "UpgradeDialogUserWidget.h"

void UUpgradeDialogUserWidget::OnButtonUpgrade()
{
	UpgradeDelegate();
}

void UUpgradeDialogUserWidget::OnButtonDestroy()
{
	DestroyDelegate();
}

void UUpgradeDialogUserWidget::Init(std::function<void()> upgradeDelegate, std::function<void()> destroyDelegate, FString name, int32 level, int32 health, int32 attack, int32 speed, int32 range, int32 cost, bool canUpgrade)
{
	UpgradeDelegate = upgradeDelegate;
	DestroyDelegate = destroyDelegate;
	TowerName = FString::Printf(TEXT("%s lv.%d"), *name, level);
	Health = health;
	Attack = attack;
	Speed = speed;
	Range = range;
	Cost = cost;
	bCanUpgrade = canUpgrade;
}