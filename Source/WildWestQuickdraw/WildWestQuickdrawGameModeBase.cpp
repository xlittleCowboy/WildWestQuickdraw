// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cowboy.h"
#include "CowboyWidget.h"
#include "Blueprint/UserWidget.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "Bottle.h"
#include "WildWestQuickdrawGameModeBase.h"

void AWildWestQuickdrawGameModeBase::BeginPlay()
{
	TArray<AActor*> Bottles;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABottle::StaticClass(), Bottles);

	BottlesInLevel = Bottles.Num();
	HitedBottles = -1;
	ShootedBullets = -1;

	if (GameWidgetClass)
	{
		GameWidget = Cast<UCowboyWidget>(CreateWidget(GetWorld(), GameWidgetClass));

		if (GameWidget)
		{
			GameWidget->AddToViewport();
			UpdateBulletText();
			UpdateBottleText();
			UpdateAccuracyText();
		}
	}
}

void AWildWestQuickdrawGameModeBase::UpdateBulletText()
{
	ACowboy* CowboyRef = Cast<ACowboy>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (CowboyRef)
	{
		GameWidget->SetBulletText(CowboyRef->GetAmmo(), CowboyRef->GetMaxAmmo());
	}
}

void AWildWestQuickdrawGameModeBase::UpdateBottleText()
{
	HitedBottles++;
	GameWidget->SetBottleText(HitedBottles, BottlesInLevel);
}

void AWildWestQuickdrawGameModeBase::UpdateExternalCrosshairScale(float CurrentRestTime, float RestTime)
{
	GameWidget->SetExternalCrosshairScale(CurrentRestTime, RestTime);
}

void AWildWestQuickdrawGameModeBase::UpdateAccuracyText()
{
	ShootedBullets++;
	GameWidget->SetAccuracyText(ShootedBullets, HitedBottles, BottlesInLevel);
}
