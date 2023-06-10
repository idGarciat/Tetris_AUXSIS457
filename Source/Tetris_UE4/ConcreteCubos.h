// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CuboDecorator.h"
#include "ConcreteCubos.generated.h"

UCLASS()
class TETRIS_UE4_API AConcreteCubos : public AActor, public ICuboDecorator
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConcreteCubos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void CambioMaterial() {};
	virtual int Contador() { return 100; };
	virtual void Desaparecer() {};
	virtual void CambioLocalizacion() {};

};
