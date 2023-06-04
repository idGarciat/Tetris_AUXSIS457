// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Suscriptor.h"
#include "Publicador.generated.h"

UCLASS()
class TETRIS_UE4_API APublicador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublicador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The Subscribers of this Publisher
	UPROPERTY()
		TArray<AActor*> Suscriptores = TArray<AActor*>();


public:
	//Add the pased Subscriber to the list
	virtual void Suscribirse(AActor* Suscriptor);
	//Remove the passed Subscriber from the list
	virtual void Desuscribirse(AActor* SuscriptorAquitar);
	//Notify all the Subscribers that something has changed
	virtual void NorificarSuscriptores();



};
