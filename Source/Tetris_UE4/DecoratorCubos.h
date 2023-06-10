// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CuboDecorator.h"
#include "DecoratorCubos.generated.h"

UCLASS()
class TETRIS_UE4_API ADecoratorCubos : public AActor, public ICuboDecorator
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecoratorCubos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ICuboDecorator* CuboDecorator;

public:
	virtual void CambioMaterial() override;
	virtual int Contador() override;
	virtual void Desaparecer() override;
	virtual void CambioLocalizacion() override;

	void DefinirCubo(ICuboDecorator* _CuboDecorator) { CuboDecorator = _CuboDecorator; }
	ICuboDecorator* GetCuboDecorator() { return CuboDecorator; }


};
