// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboInsertadoState.h"
#include "OldBoard.h"

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

void ACuboInsertadoState::DefinirBoard(AOldBoard* Board)
{
	OldBoard = Board;
}

void ACuboInsertadoState::InsertarCubo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Cubo insertado"));
}

void ACuboInsertadoState::RechazarCubo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Cubo rechazado"));
	OldBoard->DefinirEstado(OldBoard -> GetSinCubosState());
}

void ACuboInsertadoState::JalarPalanca()
{
	// Log the Pull Lever string and set the state to "Won Dollars State"
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Palanca jalada"));
	OldBoard->DefinirEstado(OldBoard-> GetBloquesGanadosState());
}

void ACuboInsertadoState::Pagar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Pagando"));
}

void ACuboInsertadoState::RellenarBloques()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Rellenando"));
}

FString ACuboInsertadoState::ToString()
{
	return "Esperando que se jale la palanca denuevo";
}



