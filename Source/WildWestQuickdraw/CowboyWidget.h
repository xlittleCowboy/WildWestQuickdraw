// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CowboyWidget.generated.h"

/**
 * 
 */
UCLASS()
class WILDWESTQUICKDRAW_API UCowboyWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
		void SetBulletText(int32 RemainingBullets, int32 MaxBullets);

	UFUNCTION(BlueprintImplementableEvent)
		void SetAccuracyText(int32 ShootedBullets, int32 HitedBottles, int32 MaxBottles);

	UFUNCTION(BlueprintImplementableEvent)
		void SetBottleText(int32 HitedBottles, int32 MaxBottles);

	UFUNCTION(BlueprintImplementableEvent)
		void SetExternalCrosshairScale(float CurrentRestTime, float RestTime);
};
