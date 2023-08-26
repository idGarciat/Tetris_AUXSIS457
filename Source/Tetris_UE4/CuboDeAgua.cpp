// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboDeAgua.h"

void ACuboDeAgua::CambioMaterial()
{
	Super::CambioMaterial();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se cambio el material a uno de agua")));
}



//aslkdjalksdjaiosdu


int ACuboDeAgua::Contador()
{
	//Devuelve el contador + 45
	return Super::Contador() + 45;
}

void ACuboDeAgua::Desaparecer()
{
	Super::Desaparecer();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El cubo desaparecio(Cubo de agua)")));
}

void ACuboDeAgua::CambioLocalizacion()
{
	Super::CambioLocalizacion();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se cambió la localizacion del cubo (Cubo de agua)")));
}

