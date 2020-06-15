#include "EnemyBase.h"

#include "Engine/World.h"
#include "TowerDefenseGameState.h"

AEnemyBase::AEnemyBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	// 放置在起点
	SetActorLocation(FVector(XArr[CurStage], YArr[CurStage], 200));
	PreLocation = FVector(XArr[CurStage], YArr[CurStage], 200);
}

void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurStage == 5) {
		GetWorld()->GetGameState<ATowerDefenseGameState>()->Damage(Damage);
		Destroy();
	}
	else {
		FVector CurLocation = PreLocation;
		FVector Target = FVector(XArr[CurStage + 1], YArr[CurStage + 1], 200);
		FVector Dir = (Target - CurLocation).GetSafeNormal();
		FVector NextLocation = CurLocation + Dir * Speed * DeltaTime;
		SetActorLocation(NextLocation);
		PreLocation = NextLocation;
		if ((NextLocation - Target).SizeSquared2D() <= 3)
			CurStage++;
	}
}

float AEnemyBase::TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser)
{
	Health -= (int32)DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Hit health %d"), Health);
	if (Health <= 0) Destroy();
	return DamageAmount;
}
