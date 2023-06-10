// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Libro/SlingShot.h"
#include "GunAdapter.generated.h"


class AGun;
UCLASS()
class TETRIS_UE4_API AGunAdapter : public AActor, public ISlingShot
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunAdapter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The Weapon Actor
	UPROPERTY();
	AGun* Weapon;

	//Fire the Weapon
	void Sling() override;
	
	void Sling2() override;

};
