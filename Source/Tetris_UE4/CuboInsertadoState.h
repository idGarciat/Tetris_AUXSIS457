// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "CuboInsertadoState.generated.h"

UCLASS()
class TETRIS_UE4_API ACuboInsertadoState : public AActor, public IEstado
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACuboInsertadoState();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The Slot Machine of this State
	UPROPERTY()
		class AOldBoard* OldBoard;

public:
	//Execute the routine when a coin is inserted
	virtual void InsertarCubo() override;
	//Execute the routine when a coin is rejected
	virtual void RechazarCubo() override;
	//Execute the routine when the lever is pulled
	virtual void JalarPalanca() override;
	//Execute the routine of the payout
	virtual void Pagar() override;
	//Restock the Slot Machine
	virtual void RellenarBloques() override;
	//Get the String this State
	virtual FString ToString() override;
	//Set the Slot Machine of this state
	virtual void DefinirBoard(class AOldBoard* Board)override;

};
