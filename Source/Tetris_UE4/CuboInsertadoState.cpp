// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboInsertadoState.h"

// Sets default values
ACuboInsertadoState::ACuboInsertadoState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACuboInsertadoState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACuboInsertadoState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACuboInsertadoState::InsertarCubo()
{
}

void ACuboInsertadoState::RechazarCubo()
{
}

void ACuboInsertadoState::JalarPalanca()
{
}

void ACuboInsertadoState::Pagar()
{
}

void ACuboInsertadoState::RellenarBloques()
{
}

FString ACuboInsertadoState::ToString()
{
	return FString();
}

void ACuboInsertadoState::DefinirBoard(AOldBoard* Board)
{
}

