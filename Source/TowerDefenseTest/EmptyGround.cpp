#include "EmptyGround.h"

#include "Blueprint/UserWidget.h"
#include "BuildDialogUserWidget.h"
#include "TowerDefenseGameState.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "ArrowTower.h"
#include "BombTower.h"

AEmptyGround::AEmptyGround()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> GroundMesh(TEXT("/Game/Geometry/Meshes/EmptyGround.EmptyGround"));

	// 网格体组件
	auto Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GroundMesh"));
	Mesh->SetStaticMesh(GroundMesh.Object);
	RootComponent = Mesh;

	// 点击事件
	Mesh->OnClicked.AddDynamic(this, &AEmptyGround::OnClick);
}

void AEmptyGround::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEmptyGround::OnClick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	if (BuildDialogInstance) {
		BuildDialogInstance->RemoveFromViewport();
		BuildDialogInstance = nullptr;
	}
	if (UClass* DialogClass = LoadClass<UUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/TwinStick/BuildDialogBlueprint.BuildDialogBlueprint_C'"))) {
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController()) {
			BuildDialogInstance = CreateWidget<UUserWidget>(PC, DialogClass);
			if (BuildDialogInstance) {
				auto State = GetWorld()->GetGameState<ATowerDefenseGameState>();
				((UBuildDialogUserWidget*)BuildDialogInstance)->Init([this]() { BuildArrowTower(); }, [this]() { BuildBombTower(); }, State->Money >= 8, State->Money >= 15);
				BuildDialogInstance->AddToViewport();
			}
		}
	}
}

void AEmptyGround::BuildArrowTower()
{
	GetWorld()->GetGameState<ATowerDefenseGameState>()->Money -= 8;
	GetWorld()->SpawnActor<AArrowTower>(GetActorLocation(), GetActorRotation());
	Destroy();
}

void AEmptyGround::BuildBombTower()
{
	GetWorld()->GetGameState<ATowerDefenseGameState>()->Money -= 15;
	GetWorld()->SpawnActor<ABombTower>(GetActorLocation(), GetActorRotation());
	Destroy();
}
