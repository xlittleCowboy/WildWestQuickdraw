// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
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
		void SetBulletInfo(int32 RemainingBullets, int32 MaxBullets);

	UFUNCTION(BlueprintImplementableEvent)
		void SetAccuracyInfo(int32 Accuracy, float TimeInSeconds);

	UFUNCTION(BlueprintImplementableEvent)
		void SetBottleInfo(int32 HitedBottles, int32 MaxBottles);

	UFUNCTION(BlueprintImplementableEvent)
		void SetExternalCrosshairScale(float CurrentRestTime, float RestTime);

	UFUNCTION(BlueprintImplementableEvent)
		TArray<FName> GetLevelsNames();

	UFUNCTION(BlueprintCallable)
		void LoadNextLevel();

	UFUNCTION(BlueprintCallable)
		void RestartLevel();
};
