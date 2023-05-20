// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "BloqueGeneral.h"
#include "ConstructorBloque.h"
#include "Block_Explosivo.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ABlock_Explosivo : public ABlock, public IConstructorBloque
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



private:
	UPROPERTY(VisibleAnywhere, Category = "El Bloque general")
		class ABloqueGeneral* BloqueGeneral;

public:
	//Create the Swimming Pool
	virtual void ContruirTamanoBloque() override;
	//Create the Lobby Area
	virtual void ConstruirColorBloque() override;
	//Create the Restaurants
	virtual void ConstruirMaterial() override;

	//Returns the Lodging
	virtual class ABloqueGeneral* GetBloqueGeneral() override;


public:
	UPROPERTY(EditAnywhere, Category = "Materiales")
		class UMaterialInterface* Material1;

};
