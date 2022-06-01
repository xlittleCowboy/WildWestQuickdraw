// Fill out your copyright notice in the Description page of Project Settings.


#include "Cowboy.h"

#include "Projectile.h"

// Sets default values
ACowboy::ACowboy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACowboy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACowboy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACowboy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//InputComponent->BindAction("Fire", IE_Pressed, this, &ACowboy::Fire);
}

void ACowboy::Fire()
{
	UWorld* World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		FRotator Rotator;
		
		AProjectile* Projectile = World->SpawnActor<AProjectile>(ProjectileClass, GetStartProjectileLocation(), Rotator, SpawnParams);
		if (Projectile)
		{
			Projectile->FireInDirection(GetStartProjectileDirection());
		}
	}
}

