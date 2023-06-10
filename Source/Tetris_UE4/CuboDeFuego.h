// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DecoratorCubos.h"
#include "CuboDeFuego.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ACuboDeFuego : public ADecoratorCubos
{
	GENERATED_BODY()
	
public:

	virtual void CambioMaterial() override;
	virtual int Contador() override;
	virtual void Desaparecer() override;
	virtual void CambioLocalizacion() override;
};
