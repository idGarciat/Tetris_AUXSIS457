// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CuboGeneralFacade.h"
#include "CuboAleatorioFacade.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ACuboAleatorioFacade : public ACuboGeneralFacade
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACuboAleatorioFacade();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Interface Duty function - Prints the Duty log
	virtual void Tarea() override;
	//Interface Duty function - Returns the title
	virtual FString NombreCubo() override;
	
};
