#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EmptyGround.generated.h"

class UUserWidget;

UCLASS()
class TOWERDEFENSETEST_API AEmptyGround : public AActor
{
	GENERATED_BODY()
	
public:
	AEmptyGround();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
		void OnClick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

	void BuildArrowTower();
	void BuildBombTower();

private:
	UUserWidget* BuildDialogInstance = nullptr;

};
