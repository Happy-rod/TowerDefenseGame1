#include "TowerBase.h"

#include "EmptyGround.h"
#include "Blueprint/UserWidget.h"
#include "UpgradeDialogUserWidget.h"
#include "TowerDefenseGameState.h"

ATowerBase::ATowerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	OnClicked.AddDynamic(this, &ATowerBase::OnClick);
}

void ATowerBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATowerBase::Upgrade()
{
}

void ATowerBase::DestroyTower()
{
	GetWorld()->SpawnActor<AEmptyGround>(GetActorLocation(), GetActorRotation());
	Destroy();
}

void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATowerBase::OnClick(AActor* TouchedActor, FKey ButtonPressed)
{
	if (UpgradeDialogInstance) {
		UpgradeDialogInstance->RemoveFromViewport();
		UpgradeDialogInstance = nullptr;
	}

	if (UClass* UpgradeDialogClass = LoadClass<UUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/TwinStick/UpgradeDialogBlueprint.UpgradeDialogBlueprint_C'"))) {
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController()) {
			UpgradeDialogInstance = CreateWidget<UUserWidget>(PC, UpgradeDialogClass);
			if (UpgradeDialogInstance) {
				bool bCanUpgrade = GetWorld()->GetGameState<ATowerDefenseGameState>()->Money >= Cost;
				((UUpgradeDialogUserWidget*)UpgradeDialogInstance)->Init([this]() { Upgrade(); }, [this]() { DestroyTower(); }, Name, Level, Health, Attack, Speed, Range, Cost, bCanUpgrade);
				UpgradeDialogInstance->AddToViewport();
			}
		}
	}
}
