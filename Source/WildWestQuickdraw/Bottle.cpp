// Fill out your copyright notice in the Description page of Project Settings.


#include "Bottle.h"

#include "Projects.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
ABottle::ABottle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABottle::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ABottle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABottle::DestroyBottle()
{
	AWildWestQuickdrawGameModeBase* GameModeBaseRef = Cast<AWildWestQuickdrawGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameModeBaseRef)
	{
		UGameplayStatics::PlaySoundAtLocation(this, GlassSound, GetActorLocation());
		GameModeBaseRef->UpdateBottleText();
		Destroy();
	}
}

