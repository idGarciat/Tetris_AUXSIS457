// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboDeFuego.h"

void ACuboDeFuego::CambioMaterial()
{
	Super::CambioMaterial();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se cambio el material a uno de fuego")));
}

int ACuboDeFuego::Contador()
{
	//Devuelve el contador + 45
	return Super::Contador() + 45;
}

void ACuboDeFuego::Desaparecer()
{
	Super::Desaparecer();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El cubo desaparecio(Cubo de fuego)")));
}

void ACuboDeFuego::CambioLocalizacion()
{
	Super::CambioLocalizacion();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se cambió la localizacion del cubo (Cubo de fuego)")));
}
