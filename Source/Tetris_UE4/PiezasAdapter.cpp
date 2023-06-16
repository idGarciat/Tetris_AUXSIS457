// Fill out your copyright notice in the Description page of Project Settings.


#include "PiezasAdapter.h"
#include "Bloques.h"

// Sets default values
APiezasAdapter::APiezasAdapter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APiezasAdapter::BeginPlay()
{
	Super::BeginPlay();

	//Spawn the Weapon
	Cubos = GetWorld()->SpawnActor<ABloques>(ABloques::StaticClass());

}

// Called every frame
void APiezasAdapter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APiezasAdapter::Sling()
{
	if (!Cubos) {UE_LOG(LogTemp, Error, TEXT("Sling(): Weapon isNULL, make sure it's initialized."));
	
	return; }
	//Call the Fire function
	Cubos->Fuego();

}

void APiezasAdapter::Cambiar()
{
	Cubos->Opcion2();
}


