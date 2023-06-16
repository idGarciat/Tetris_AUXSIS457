// Fill out your copyright notice in the Description page of Project Settings.


#include "PiezasStrategy.h"

// Sets default values
APiezasStrategy::APiezasStrategy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APiezasStrategy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APiezasStrategy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APiezasStrategy::AlterarManiobras(AActor* myEstrategiadepiezas)
{
	//Try to cast the passed Strategy and set it to the current one
	EstrategiasDePiezas = Cast<IEstrategiasDePiezas>(myEstrategiadepiezas);
}

void APiezasStrategy::Comprometer()
{
	EstrategiasDePiezas->Maniobra();

}

