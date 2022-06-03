// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

#include "EditorTutorial.h"

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
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	GetWorld()->SpawnActor<AActor>(ForceFieldClass, GetActorLocation(), GetActorRotation());

	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulseAtLocation(GetProjectileMovementComponent()->Velocity * 100.0f, Hit.ImpactPoint);
	}
	
	Destroy();
}

void AProjectile::FireInDirection(const FVector& ShootDirection)
{
	GetProjectileMovementComponent()->Velocity = ShootDirection * GetProjectileMovementComponent()->InitialSpeed;
}

