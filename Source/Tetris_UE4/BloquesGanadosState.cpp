// Fill out your copyright notice in the Description page of Project Settings.


#include "BloquesGanadosState.h"
#include "OldBoard.h"

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

void ABloquesGanadosState::DefinirBoard(AOldBoard* Board)
{
	OldBoard = Board;
}

void ABloquesGanadosState::InsertarCubo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Cubo insertado"));
}

void ABloquesGanadosState::RechazarCubo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Cubo rechazado"));
}

void ABloquesGanadosState::JalarPalanca()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Palanca jalada"));
}

void ABloquesGanadosState::Pagar()
{
	OldBoard->EmitirBloques();
	if (OldBoard->GetContador() > 0)
	{
		//If the Slot Machine still have dollars, set its state to No Coin State
		OldBoard->DefinirEstado(OldBoard -> GetSinCubosState());
	}
	else
	{
		//If the Slot Machine doesn't have any dollars left, log it and set its state to No Dollars State
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("No hay bloques"));
		OldBoard->DefinirEstado(OldBoard-> GetSinBloquesState());
	}

}

void ABloquesGanadosState::RellenarBloques()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Rellenado"));
}

FString ABloquesGanadosState::ToString()
{
	return "Soltando bloques";
}


