// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloques.generated.h"

UCLASS()
class TETRIS_UE4_API ABloques : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloques();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Fire with the gun
	void Fuego();
	void Opcion2();

};