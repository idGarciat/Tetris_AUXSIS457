// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovimientoSling.h"
#include "PiezasAdapter.generated.h"


class ABloques;
UCLASS()
class TETRIS_UE4_API APiezasAdapter : public AActor, public IMovimientoSling
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiezasAdapter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The Weapon Actor
	UPROPERTY();
	ABloques* Cubos;

public:
	//Fire the Weapon
	void Sling() override;

	void Cambiar() override;
};
