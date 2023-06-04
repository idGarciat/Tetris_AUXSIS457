// Fill out your copyright notice in the Description page of Project Settings.


#include "Senalador.h"

ASenalador::ASenalador()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASenalador::BeginPlay()
{
	Super::BeginPlay();

}

void ASenalador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASenalador::EstadoCambiado()
{
	//When the time has changed, this Clock Tower (that is a Publisher) notifies to all the subscribers that the time has changed
	NorificarSuscriptores();

}

void ASenalador::DefinirEstado(FString myEstado)
{
	//Set the time using the passed parameter and warn that it's changed
	Estado = myEstado;
	EstadoCambiado();

}
