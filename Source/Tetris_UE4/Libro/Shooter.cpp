// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/Shooter.h"

// Sets default values
AShooter::AShooter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShooter::SetSlingShot(AActor* SlingShotObj)
{
	//Cast the passed Actor and set the Weapon
	SlingShot = Cast<ISlingShot>(SlingShotObj);
	if (!SlingShot) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("SetSlingShot(): The Actor is not aSlingShot!Are you sure that the Actor implements that interface ? "));
	}

}

void AShooter::Sling()
{
	if (!SlingShot) {UE_LOG(LogTemp, Error, TEXT("Sling(): SlingShot isNULL, make sure it's initialized.")); return; }
	//Fire
	SlingShot->Sling();

}

void AShooter::Sling2()
{
	if (!SlingShot) { UE_LOG(LogTemp, Error, TEXT("Sling(): SlingShot isNULL, make sure it's initialized.")); return; }
	//Fire
	SlingShot->Sling2();

}

