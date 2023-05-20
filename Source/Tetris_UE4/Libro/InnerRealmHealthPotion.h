// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Libro/Potion.h"
#include "InnerRealmHealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AInnerRealmHealthPotion : public APotion
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	//Brew the potion
	virtual void Brew() override;

};
