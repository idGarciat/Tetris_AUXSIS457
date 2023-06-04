// Fill out your copyright notice in the Description page of Project Settings.


#include "OldBoard.h"
#include "SinBloquesState.h"
#include "SinCubosState.h"
#include "CuboInsertadoState.h"
#include "BloquesGanadosState.h"

// Sets default values
AOldBoard::AOldBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOldBoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOldBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOldBoard::Inicializar(int NumerodeBloques)
{
	//Spanw the No Dollars State and set this Slot Machine to it
	SinBloquesState = GetWorld()->SpawnActor<ASinBloquesState>(ASinBloquesState::StaticClass());
	SinBloquesState->DefinirBoard(this);

	//Spanw the No Coin State and set this Slot Machine to it
	SinCubosState = GetWorld()->SpawnActor<ASinCubosState>(ASinCubosState::StaticClass());
	SinCubosState->DefinirBoard(this);

	//Spanw the Coin Inserted State and set this Slot Machine to it
	CuboInsertadoState = GetWorld()->SpawnActor<ACuboInsertadoState>(ACuboInsertadoState::StaticClass());
	CuboInsertadoState->DefinirBoard(this);

	//Spanw the Won Dollars State and set this Slot Machine to it
	BloquesGanadosState = GetWorld()->SpawnActor<ABloquesGanadosState>(ABloquesGanadosState::StaticClass());
	BloquesGanadosState->DefinirBoard(this);

	//Set the amount of dollars
	Contador = NumerodeBloques;
	//If its greater than 0, set the current State to No Coin State
	if (NumerodeBloques > 0) {
		Estado = SinCubosState;
	}
	else {
		Estado = SinBloquesState;
	}

}

void AOldBoard::InsertarCubo()
{
	Estado->InsertarCubo();
}

void AOldBoard::RechazarCubo()
{
	Estado->RechazarCubo();
}

void AOldBoard::JalarPalanca()
{
	Estado->JalarPalanca();
	Estado->Pagar();
}


void AOldBoard::EmitirBloques()
{
	//You won!
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Ganaste!!!!!!!"));
	//If the Slot Machine still have some dollars, decrease them by 50
	if (Contador != 0) {
		Contador = Contador - 50;
	}
}


void AOldBoard::RellenarBloques(int myContador)
{
	// Add the passed count to the Dollars amount and log it
	Contador += myContador;
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("The Old School Slot Machine was just filled and new dollar count is : % i"), Contador));
			//Then execute the Restock Dollars routine based on the current state
	Estado->RellenarBloques();

}


void AOldBoard::DefinirEstado(IEstado* myEstado)
{
	//Set the current state to the passed one
	Estado = myEstado;
}

IEstado* AOldBoard::GetEstado()
{
	return Estado;
}

int AOldBoard::GetContador()
{

	return Contador;
}



IEstado* AOldBoard::GetSinBloquesState()
{

	return SinBloquesState;
}

IEstado* AOldBoard::GetSinCubosState()
{

	return SinCubosState;
}

IEstado* AOldBoard::GetCuboInsertadoState()
{

	return CuboInsertadoState;
}

IEstado* AOldBoard::GetBloquesGanadosState()
{
	return BloquesGanadosState;
}


FString AOldBoard::GetEstadoActual()
{
	return "El estado actual del board es: " + Estado->ToString();
}



