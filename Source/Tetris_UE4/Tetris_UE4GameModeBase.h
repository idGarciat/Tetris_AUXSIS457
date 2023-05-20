// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Tetris_UE4GameModeBase.generated.h"

/**
 * 
 */


UCLASS()
class TETRIS_UE4_API ATetris_UE4GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
    ATetris_UE4GameModeBase();
    virtual void BeginPlay() override;

	class ABoard* Board;



	//Patrón Builder

	//The Builder Actor
	UPROPERTY(VisibleAnywhere, Category = "Main")
		class ABlock_Explosivo* Block_Explosivo;
	////The Engineer Actor
	//UPROPERTY(VisibleAnywhere, Category = "Main")
		class AIngeniero_Bloques* Ingeniero;

		UPROPERTY(VisibleAnywhere, Category = "Main")
		class ABlock_HIelo* Block_HIelo;



		FTimerHandle Cronometro;

		void cambiar();

};
