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

void ASinBloquesState::DefinirBoard(AOldBoard* Board)
{
	OldBoard = Board;
}


void ASinBloquesState::InsertarCubo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Cubo insertado"));
}

void ASinBloquesState::RechazarCubo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Cubo rechazado"));
}

void ASinBloquesState::JalarPalanca()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Se jaló la palanca"));
}

void ASinBloquesState::Pagar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Recibiendo pago"));
}

void ASinBloquesState::RellenarBloques()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Rellenando bloques"));
}

FString ASinBloquesState::ToString()
{
	return "La maquina esta sin bloques";
}



