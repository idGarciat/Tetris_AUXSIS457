// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboDeTierra.h"

void ACuboDeTierra::CambioMaterial()
{
	Super::CambioMaterial();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se cambio el material a uno de tierra")));
}

int ACuboDeTierra::Contador()
{
	//Devuelve el contador + 45
	return Super::Contador() + 45;

}

void ACuboDeTierra::Desaparecer()
{
	Super::Desaparecer();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El cubo desaparecio(Cubo de tierra)")));
}

void ACuboDeTierra::CambioLocalizacion()
{
	Super::CambioLocalizacion();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se cambió la localizacion del cubo (Cubo de tierra)")));
}
