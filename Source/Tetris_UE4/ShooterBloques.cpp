// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterBloques.h"

// Sets default values
AShooterBloques::AShooterBloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterBloques::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooterBloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShooterBloques::DefinirMovimientoSling(AActor* MovimientoSlingObj)
{
	//Cast the passed Actor and set the Weapon
	MovimientoSling = Cast<IMovimientoSling>(MovimientoSlingObj);
	if (!MovimientoSling) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,TEXT("Invalid Cast! See Output log for more details"));UE_LOG(LogTemp, Error, TEXT("SetSlingShot(): The Actor is not aSlingShot!Are you sure that the Actor implements that interface ? "));
	}

}

void AShooterBloques::Sling()
{
	if (!MovimientoSling) {UE_LOG(LogTemp, Error, TEXT("Sling(): SlingShot isNULL, make sure it's initialized.")); return; }
		//Fire
	MovimientoSling->Sling();

}

void AShooterBloques::Cambiar()
{
	MovimientoSling->Cambiar();
}



