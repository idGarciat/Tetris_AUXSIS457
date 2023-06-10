// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoratorCubos.h"

// Sets default values
ADecoratorCubos::ADecoratorCubos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecoratorCubos::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADecoratorCubos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecoratorCubos::CambioMaterial()
{
}

int ADecoratorCubos::Contador()
{
	return 0;
}

void ADecoratorCubos::Desaparecer()
{
}

void ADecoratorCubos::CambioLocalizacion()
{
}

