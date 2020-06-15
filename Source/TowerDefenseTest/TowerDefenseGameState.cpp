#include "TowerDefenseGameState.h"

#include "EngineUtils.h"
#include "Blueprint/UserWidget.h"

#include "EnemyBase.h"
#include "PlayerInfoUserWidget.h"

ATowerDefenseGameState::ATowerDefenseGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATowerDefenseGameState::BeginPlay()
{
	if (PlayerInfoWidgetInstance) {
		PlayerInfoWidgetInstance->RemoveFromViewport();
		PlayerInfoWidgetInstance = nullptr;
	}

	if (UClass* DialogClass = LoadClass<UUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/TwinStick/PlayerInfoBlueprint.PlayerInfoBlueprint_C'"))) {
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController()) {
			PlayerInfoWidgetInstance = CreateWidget<UUserWidget>(PC, DialogClass);
			if (PlayerInfoWidgetInstance) {
				((UPlayerInfoUserWidget*)PlayerInfoWidgetInstance)->Health = Health;
				((UPlayerInfoUserWidget*)PlayerInfoWidgetInstance)->Money = Money;
				PlayerInfoWidgetInstance->AddToViewport();
			}
		}
	}

	if (GameResultWidgetInstance) {
		GameResultWidgetInstance->RemoveFromParent();
		GameResultWidgetInstance = nullptr;
	}
}

void ATowerDefenseGameState::Tick(float DeltaTime)
{
	Timer += DeltaTime;
	if (Timer >= 3)
		Money += 2, Timer -= 3;
	((UPlayerInfoUserWidget*)PlayerInfoWidgetInstance)->Money = Money;

	if (bCanWin && !GameResultWidgetInstance && !TActorIterator<AEnemyBase>(GetWorld())) {
		if (UClass* DialogClass = LoadClass<UUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/TwinStick/WinBlueprint.WinBlueprint_C'"))) {
			if (APlayerController* PC = GetWorld()->GetFirstPlayerController()) {
				GameResultWidgetInstance = CreateWidget<UUserWidget>(PC, DialogClass);
				if (GameResultWidgetInstance) {
					GameResultWidgetInstance->AddToViewport();
				}
			}
		}
	}
}

void ATowerDefenseGameState::Damage(int32 Damage)
{
	Health -= Damage;
	((UPlayerInfoUserWidget*)PlayerInfoWidgetInstance)->Health = Health;

	// ÅÐ¶¨Ê§°Ü
	if (Health <= 0) {
		if (UClass* DialogClass = LoadClass<UUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/TwinStick/LoseBlueprint.LoseBlueprint_C'"))) {
			if (APlayerController* PC = GetWorld()->GetFirstPlayerController()) {
				GameResultWidgetInstance = CreateWidget<UUserWidget>(PC, DialogClass);
				if (GameResultWidgetInstance) {
					GameResultWidgetInstance->AddToViewport();
				}
			}
		}
	}
}

void ATowerDefenseGameState::Cost(int32 Cost)
{
	Money -= Cost;
	((UPlayerInfoUserWidget*)PlayerInfoWidgetInstance)->Money = Money;
}

void ATowerDefenseGameState::Win()
{
	// Ê¤Àû
	bCanWin = true;
}
