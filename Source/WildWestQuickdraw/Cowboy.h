// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WildWestQuickdrawGameModeBase.h"
#include "Cowboy.generated.h"

UCLASS()
class WILDWESTQUICKDRAW_API ACowboy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACowboy();

private:
	UPROPERTY()
		FTimerHandle ReloadTimerHandle;

	UPROPERTY(EditAnywhere)
		float RestTime;

	float CurrentRestTime;

	AWildWestQuickdrawGameModeBase* GameModeBaseRef;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Projectile)
		TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
		USoundBase* ReloadSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
		USoundBase* FireSound;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Projectile)
		int32 MaxBulletsCount;

	UPROPERTY()
		int32 BulletsCount;

	UFUNCTION(BlueprintImplementableEvent)
		FVector GetStartProjectileLocation();

	UFUNCTION(BlueprintImplementableEvent)
		FVector GetStartProjectileDirection();

	UFUNCTION()
		void XInput(float Angle);

	UFUNCTION()
		void YInput(float Angle);
	
    UFUNCTION(BlueprintCallable)
		void Fire();

	UPROPERTY()
		float TraceDistance;

	UFUNCTION()
		void Reload();

	UFUNCTION(BlueprintCallable)
		int32 GetAmmo();

	UFUNCTION()
		int32 GetMaxAmmo();

	UFUNCTION()
		void ReloadTimer();
};
