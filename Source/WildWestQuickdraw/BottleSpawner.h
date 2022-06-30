// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "WildWestQuickdrawGameModeBase.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "BottleSpawner.generated.h"

UCLASS()
class WILDWESTQUICKDRAW_API ABottleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABottleSpawner();

private:
	AWildWestQuickdrawGameModeBase* GameModeBaseRef;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpawnRate;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TArray<AActor*> BottlesPositions;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> BottleClass;

	FTimerHandle SpawnTimerHandle;
	void SpawnTimer();
};
