// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

#include "Math/UnitConversion.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	//GetWorld()->SpawnActor<AActor>(ForceFieldClass, GetActorLocation(), GetActorRotation());
	
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
		OtherComponent->AddImpulseAtLocation(GetProjectileMovementComponent()->Velocity * 100.0f, Hit.ImpactPoint);

	if (OtherActor->ActorHasTag("Bottle"))
	{
		ABottle* BottleRef = Cast<ABottle>(OtherActor);
		if (BottleRef)
		{
			BottleRef->DestroyBottle();
		}
	}

	Destroy();
}

void AProjectile::FireInDirection(const FVector& ShootDirection)
{
	GetProjectileMovementComponent()->Velocity = ShootDirection.GetSafeNormal() * GetProjectileMovementComponent()->InitialSpeed;
}

