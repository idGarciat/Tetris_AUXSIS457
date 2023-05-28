// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Escenario.h"
#include "Escenario_2.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AEscenario_2 : public AEscenario
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	//Brew the potion
	virtual void Elaborar() override;

	
};
