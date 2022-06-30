// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WildWestQuickdrawGameModeBase.generated.h"

/**
 * 
 */

class UCowboyWidget;

UCLASS()
class WILDWESTQUICKDRAW_API AWildWestQuickdrawGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = Widgets)
		TSubclassOf<class UUserWidget> GameWidgetClass;

	UPROPERTY()
		UCowboyWidget* GameWidget;

	int32 BottlesInLevel;
	int32 HitedBottles;

	int32 ShootedBullets;

	virtual void BeginPlay() override;

public:
	void UpdateBulletText();
	void UpdateBottleText(bool isHitted = true);
	void UpdateExternalCrosshairScale(float CurrentRestTime, float RestTime);
	void UpdateAccuracyText();

	UFUNCTION(BlueprintCallable)
	void AddBottlesInlevel(int32 BottlesNum);

	int32 GetHitedBottles();
	int32 GetBottlesInlevel();
};
