// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Libro/BattleShipStrategy.h"

#include "RetreatStrategy.generated.h"

UCLASS()
class TETRIS_UE4_API ARetreatStrategy : public AActor, public IBattleShipStrategy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARetreatStrategy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Execute the Maneuver of this Strategy
	virtual void Maneuver() override;

};
