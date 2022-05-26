// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cowboy.generated.h"

UCLASS()
class WILDWESTQUICKDRAW_API ACowboy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACowboy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category=Projectile)
	TSubclassOf<class AProjectile> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	FVector GetStartProjectileLocation();

	UFUNCTION(BlueprintImplementableEvent)
	FVector GetStartProjectileDirection();
	
    UFUNCTION()
    void Fire();
};
