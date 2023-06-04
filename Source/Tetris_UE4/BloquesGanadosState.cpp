// Fill out your copyright notice in the Description page of Project Settings.


#include "BloquesGanadosState.h"

// Sets default values
ABloquesGanadosState::ABloquesGanadosState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABloquesGanadosState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloquesGanadosState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABloquesGanadosState::InsertarCubo()
{
}

void ABloquesGanadosState::RechazarCubo()
{
}

void ABloquesGanadosState::JalarPalanca()
{
}

void ABloquesGanadosState::Pagar()
{
}

void ABloquesGanadosState::RellenarBloques()
{
}

FString ABloquesGanadosState::ToString()
{
	return FString();
}

void ABloquesGanadosState::DefinirBoard(AOldBoard* Board)
{
}

