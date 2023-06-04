// Fill out your copyright notice in the Description page of Project Settings.


#include "SinBloquesState.h"

// Sets default values
ASinBloquesState::ASinBloquesState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASinBloquesState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASinBloquesState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASinBloquesState::InsertarCubo()
{
}

void ASinBloquesState::RechazarCubo()
{
}

void ASinBloquesState::JalarPalanca()
{
}

void ASinBloquesState::Pagar()
{
}

void ASinBloquesState::RellenarBloques()
{
}

FString ASinBloquesState::ToString()
{
	return FString();
}

void ASinBloquesState::DefinirBoard(AOldBoard* Board)
{
}

