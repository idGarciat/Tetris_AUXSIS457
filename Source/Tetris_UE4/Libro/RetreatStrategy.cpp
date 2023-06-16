// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/RetreatStrategy.h"

// Sets default values
ARetreatStrategy::ARetreatStrategy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARetreatStrategy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARetreatStrategy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARetreatStrategy::Maneuver()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Retreat Strategy is now active"));

}

