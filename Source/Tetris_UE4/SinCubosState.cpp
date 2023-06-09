// Fill out your copyright notice in the Description page of Project Settings.


#include "SinCubosState.h"
#include "OldBoard.h"

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

void ASinCubosState::DefinirBoard(AOldBoard* Board)
{
	OldBoard = Board;
}

void ASinCubosState::InsertarCubo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("No hay cubos"));
	OldBoard->DefinirEstado(OldBoard->GetCuboInsertadoState());

}

void ASinCubosState::RechazarCubo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Cubo rechazado"));
}

void ASinCubosState::JalarPalanca()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Palanca jalada"));
}

void ASinCubosState::Pagar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Recibiendo pago"));
}

void ASinCubosState::RellenarBloques()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Rellenando bloques"));
}

FString ASinCubosState::ToString()
{
	return "Esperando cubos";
}



