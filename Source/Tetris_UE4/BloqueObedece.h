// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Suscriptor.h"
#include "Cambios.h"
#include "BloqueObedece.generated.h"


class ASenalador;

UCLASS()
class TETRIS_UE4_API ABloqueObedece : public AActor, public ISuscriptor, public ICambios
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloqueObedece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	//The Clock Tower of this Subscriber
	UPROPERTY()
		ASenalador* Senalador;

	//Called when this Subscriber is destroyed, it will unsubscribe this from theClock Tower
		virtual void Destroyed() override;


public:
	//Called when the Plublisher changed its state, it will execute this Subscriber routine
	virtual void Actualizar(class APublicador* Publicador) override;
	//Execute this Subscriber routine
	virtual void Cambios();
	//Set the Clock Tower of this Subscriber
	void DefinirSenalador(ASenalador* mySenalador);


};
