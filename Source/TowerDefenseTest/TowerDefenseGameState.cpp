#include "TowerDefenseGameState.h"

#include "Blueprint/UserWidget.h"
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
}

void ATowerDefenseGameState::Tick(float DeltaTime)
{
	Timer += DeltaTime;
	if (Timer >= 3)
		Money += 2, Timer -= 3, ((UPlayerInfoUserWidget*)PlayerInfoWidgetInstance)->Money = Money;
}

void ATowerDefenseGameState::Damage(int Damage)
{
	Health -= Damage;
	((UPlayerInfoUserWidget*)PlayerInfoWidgetInstance)->Health = Health;
}
