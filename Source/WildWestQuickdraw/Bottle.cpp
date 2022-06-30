// Fill out your copyright notice in the Description page of Project Settings.


#include "Bottle.h"

#include "Projects.h"

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

	GetMesh()->OnComponentHit.AddDynamic(this, &ABottle::OnHit);
}

void ABottle::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (GetVelocity().Length() >= BreakSpeed)
	{
		DestroyBottle();
	}
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