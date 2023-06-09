// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decorator.generated.h"

UCLASS()
class TETRIS_UE4_API ADecorator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecorator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	//Start Fighting
	virtual void Fight();
	//Returns how much damage this enemy has taken
	virtual int GetDamage();
	//Kill this enemy
	virtual void Die();
	//Define el enemigo
	virtual void SetEnemy(AActor* ConcreteEnemy);


};
