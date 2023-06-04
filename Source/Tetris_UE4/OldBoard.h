// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "OldBoard.generated.h"

UCLASS()
class TETRIS_UE4_API AOldBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOldBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	//The No Dollars State of this Slot Machine
	IEstado* SinBloquesState;
	//The No Coin State of this Slot Machine
	IEstado* SinCubosState;
	//The Coin Inserted State of this Slot Machine
	IEstado* CuboInsertadoState;
	//The Won Dollars State of this Slot Machine
	IEstado* BloquesGanadosState;
	//The State of this Slot Machine
	IEstado* Estado;
	//The amount of Dollars of this Slot Machine
	int Contador = 0;


public:
	//Initialize this Slot Machine
	void Inicializar(int NumerodeBloques);
	//Insert a Coin
	void InsertarCubo();
	//Reject a Coin
	void RechazarCubo();
	//Pull the lever of this Slot Machine
	void JalarPalanca();
	//Get the current State of this Slot Machine
	IEstado* GetEstado();
	//Get the No Dollars State of this Slot Machine
	IEstado* GetSinBloquesState();
	//Get the No Coin State of this Slot Machine
	IEstado* GetSinCubosState();
	//Get the Coin Inserted State of this Slot Machine
	IEstado* GetCuboInsertadoState();
	//Get the Won Dollars State of this Slot Machine
	IEstado* GetBloquesGanadosState();
	//Get the String of the current State
	FString GetEstadoActual();
	//Set the Current State with the passed one
	void DefinirEstado(IEstado* myEstado);
	//Emit Dollars from this Slot Machine
	void EmitirBloques();
	//Get the amount of dollars in this Slot Machine
	int GetContador();
	//Refill the dollars by the passed amount
	void RellenarBloques(int myContador);
};
