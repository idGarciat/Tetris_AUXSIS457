// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaFuerte.h"
#include "PruebaMesh.h"

// Sets default values
AEstrategiaFuerte::AEstrategiaFuerte()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaFuerte::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaFuerte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaFuerte::Maniobra()
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("EstrategiaFuerte"));

	GetWorld()->SpawnActor<APruebaMesh>(FVector(100,100,100),FRotator::ZeroRotator);


}

