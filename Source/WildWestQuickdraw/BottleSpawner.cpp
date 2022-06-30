// Fill out your copyright notice in the Description page of Project Settings.


#include "BottleSpawner.h"

// Sets default values
ABottleSpawner::ABottleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABottleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	GameModeBaseRef = Cast<AWildWestQuickdrawGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ABottleSpawner::SpawnTimer, SpawnRate, true, SpawnRate);
}

// Called every frame
void ABottleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABottleSpawner::SpawnTimer()
{
	if (GameModeBaseRef->GetHitedBottles() < GameModeBaseRef->GetBottlesInlevel())
	{
		FRandomStream RandomStream;
		FVector RandomLocation = BottlesPositions[FMath::RandRange(0, BottlesPositions.Num() - 1)]->GetActorLocation();

		FRotator Rotator = UKismetMathLibrary::RandomRotator(true);

		GetWorld()->SpawnActor<AActor>(BottleClass, RandomLocation, Rotator);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
	}
}

