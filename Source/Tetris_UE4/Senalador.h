// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Publicador.h"
#include "Senalador.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ASenalador : public APublicador
{
	GENERATED_BODY()

public:

	ASenalador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The current time of this Clock Tower
	FString Estado;

public:
	//Called when the time of this Clock Tower has changed
	void EstadoCambiado();
	//Set the time of this Clock Tower
	void DefinirEstado(FString myEstado);
	//Return the time of this Clock Tower

	FORCEINLINE FString GetEstado() { return Estado; };

};
