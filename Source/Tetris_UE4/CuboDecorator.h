// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CuboDecorator.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCuboDecorator : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TETRIS_UE4_API ICuboDecorator
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//The pure virtual functions of the Enemy
	virtual void CambioMaterial() = 0;
	virtual int Contador() = 0;
	virtual void Desaparecer() = 0;
	virtual void CambioLocalizacion() = 0;
};
