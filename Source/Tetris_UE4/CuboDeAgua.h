// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DecoratorCubos.h"
#include "CuboDeAgua.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ACuboDeAgua : public ADecoratorCubos
{
	GENERATED_BODY()
	
public:

	virtual void CambioMaterial() override;
	virtual int Contador() override;
	virtual void Desaparecer() override;
	virtual void CambioLocalizacion() override;
};
