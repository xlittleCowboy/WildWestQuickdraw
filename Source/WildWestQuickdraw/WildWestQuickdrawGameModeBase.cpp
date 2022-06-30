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
		}
	}
}

void AWildWestQuickdrawGameModeBase::UpdateBulletText()
{
	ACowboy* CowboyRef = Cast<ACowboy>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (CowboyRef)
	{
		GameWidget->SetBulletInfo(CowboyRef->GetAmmo(), CowboyRef->GetMaxAmmo());
	}
}

void AWildWestQuickdrawGameModeBase::UpdateBottleText(bool isHitted)
{
	if (isHitted)
		HitedBottles++;
	GameWidget->SetBottleInfo(HitedBottles, BottlesInLevel);
}

void AWildWestQuickdrawGameModeBase::UpdateExternalCrosshairScale(float CurrentRestTime, float RestTime)
{
	GameWidget->SetExternalCrosshairScale(CurrentRestTime, RestTime);
}

void AWildWestQuickdrawGameModeBase::UpdateAccuracyText()
{
	ShootedBullets++;
	if (ShootedBullets > 0)
		GameWidget->SetAccuracyInfo(((float)HitedBottles / (float)ShootedBullets) * 100.0f, GetWorld()->GetTimeSeconds());
}

void AWildWestQuickdrawGameModeBase::AddBottlesInlevel(int32 BottlesNum)
{
	if (BottlesNum >= 0)
	{
		BottlesInLevel += BottlesNum;
		UpdateBottleText(false);
	}
}

int32 AWildWestQuickdrawGameModeBase::GetHitedBottles()
{
	return HitedBottles;
}

int32 AWildWestQuickdrawGameModeBase::GetBottlesInlevel()
{
	return BottlesInLevel;
}
