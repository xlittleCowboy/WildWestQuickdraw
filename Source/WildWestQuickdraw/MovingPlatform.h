// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class WILDWESTQUICKDRAW_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

private:
	FVector Target;
	FVector StartPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		FVector EndPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		float Speed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
