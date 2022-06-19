// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WildWestQuickdrawGameModeBase.h"
#include "Bottle.generated.h"

UCLASS()
class WILDWESTQUICKDRAW_API ABottle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABottle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
		USoundBase* GlassSound;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DestroyBottle();
};
