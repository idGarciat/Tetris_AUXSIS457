// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloques.h"

// Sets default values
ABloques::ABloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABloques::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABloques::Fuego()
{
	//Print Fire log
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("El bloque ta haciendo algo"));

}

void ABloques::Opcion2()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("El bloque esta haciendo otra cosa"));
}


