// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "EstrategiasDePiezas.h"

#include "PiezasStrategy.generated.h"

UCLASS()
class TETRIS_UE4_API APiezasStrategy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiezasStrategy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The current Battle Strategy
	IEstrategiasDePiezas* EstrategiasDePiezas;


public:
	// Change the Maneuver and set "BattleStrategy" variable
	void AlterarManiobras(AActor* myEstrategiadepiezas);
	// Engage with the current Battle Strategy
	void Comprometer();



};
