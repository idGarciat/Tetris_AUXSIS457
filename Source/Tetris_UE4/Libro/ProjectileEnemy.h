// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Libro/Decorator.h"
#include "ProjectileEnemy.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AProjectileEnemy : public ADecorator
{
	GENERATED_BODY()
public:
	//Start Fighting
	virtual void Fight() override;
	//Returns how much damage this enemy has taken
	virtual int GetDamage() override;
	//Kill this enemy
	virtual void Die() override;

};
