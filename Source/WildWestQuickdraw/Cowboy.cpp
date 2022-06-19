// Fill out your copyright notice in the Description page of Project Settings.


#include "Cowboy.h"
#include "Projectile.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <Runtime/Engine/Classes/Kismet/KismetMathLibrary.h>

// Sets default values
ACowboy::ACowboy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TraceDistance = 1000000.0f;

	CurrentRestTime = RestTime;
}

// Called when the game starts or when spawned
void ACowboy::BeginPlay()
{
	Super::BeginPlay();
	GameModeBaseRef = Cast<AWildWestQuickdrawGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
	BulletsCount = MaxBulletsCount;
	GameModeBaseRef->UpdateBulletText();
	GameModeBaseRef->UpdateExternalCrosshairScale(CurrentRestTime, RestTime);
}

// Called every frame
void ACowboy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentRestTime > 0)
	{
		CurrentRestTime -= DeltaTime;
		GameModeBaseRef->UpdateExternalCrosshairScale(CurrentRestTime, RestTime);
	}
}

// Called to bind functionality to input
void ACowboy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MouseX", this, &ACowboy::XInput);
	InputComponent->BindAxis("MouseY", this, &ACowboy::YInput);

	InputComponent->BindAction("Reload", IE_Pressed, this, &ACowboy::Reload);
}

void ACowboy::XInput(float Angle)
{
	AddControllerYawInput(Angle);
}

void ACowboy::YInput(float Angle)
{
	AddControllerPitchInput(Angle);
}

void ACowboy::Fire()
{
	if (BulletsCount > 0)
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
				FVector Loc;
				FRotator Rot;
				FHitResult Hit;

				GetController()->GetPlayerViewPoint(Loc, Rot);


				FVector Start = Loc;
				FVector End = Start + (Rot.Vector() * TraceDistance);

				FCollisionQueryParams TraceParams;
				bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

				FVector FireDirection;

				FVector Recoil;

				if (bHit)
				{
					FRotator BulletRot = UKismetMathLibrary::FindLookAtRotation(GetStartProjectileLocation(), Hit.Location);
					FireDirection = BulletRot.Vector();
					Recoil = FMath::VRandCone(FireDirection, 0.05f) * CurrentRestTime;
					Projectile->FireInDirection(FireDirection + Recoil);
				}
				else
				{
					Recoil = FMath::VRandCone(End, 0.05f) * CurrentRestTime;
					Projectile->FireInDirection(End + Recoil);
				}

				CurrentRestTime = RestTime;

				BulletsCount--;

				GetWorldTimerManager().ClearTimer(ReloadTimerHandle);

				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());

				GameModeBaseRef->UpdateBulletText();
				GameModeBaseRef->UpdateAccuracyText();
			}
		}
	}
}

void ACowboy::Reload()
{
	GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &ACowboy::ReloadTimer, 0.5f, true, 0.5f);
}

int32 ACowboy::GetAmmo()
{
	return BulletsCount;
}

int32 ACowboy::GetMaxAmmo()
{
	return MaxBulletsCount;
}

void ACowboy::ReloadTimer()
{
	if (BulletsCount < MaxBulletsCount)
	{
		BulletsCount++;
		UGameplayStatics::PlaySoundAtLocation(this, ReloadSound, GetActorLocation());
		GameModeBaseRef->UpdateBulletText();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(ReloadTimerHandle);
	}
}

