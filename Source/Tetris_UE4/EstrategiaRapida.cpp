// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaRapida.h"
#include "PruebaMesh.h"

// Sets default values
AEstrategiaRapida::AEstrategiaRapida()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaRapida::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaRapida::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaRapida::Maniobra()
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Estrategia Rapida"));

	GetWorld()->SpawnActor<APruebaMesh>(FVector(110, 110, 100), FRotator::ZeroRotator);
	GetWorld()->SpawnActor<APruebaMesh>(FVector(130, 130, 100), FRotator::ZeroRotator);
}

