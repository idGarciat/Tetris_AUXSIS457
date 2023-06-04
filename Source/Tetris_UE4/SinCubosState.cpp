// Fill out your copyright notice in the Description page of Project Settings.


#include "SinCubosState.h"

// Sets default values
ASinCubosState::ASinCubosState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASinCubosState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASinCubosState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASinCubosState::InsertarCubo()
{
}

void ASinCubosState::RechazarCubo()
{
}

void ASinCubosState::JalarPalanca()
{
}

void ASinCubosState::Pagar()
{
}

void ASinCubosState::RellenarBloques()
{
}

FString ASinCubosState::ToString()
{
	return FString();
}

void ASinCubosState::DefinirBoard(AOldBoard* Board)
{
}

