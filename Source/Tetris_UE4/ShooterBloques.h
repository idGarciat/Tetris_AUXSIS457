// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovimientoSling.h"
#include "ShooterBloques.generated.h"

UCLASS()
class TETRIS_UE4_API AShooterBloques : public AActor, public IMovimientoSling
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShooterBloques();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The Weapon of the Shooter, that must be a SlingShot
	IMovimientoSling* MovimientoSling;

public:
	//Set the Weapon Actor
	void DefinirMovimientoSling(AActor* MovimientoSlingObj);
	//Fire with the SlingShot
	void Sling();
	void Cambiar();


};
