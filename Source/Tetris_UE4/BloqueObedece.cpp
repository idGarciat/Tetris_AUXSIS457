// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueObedece.h"
#include "Senalador.h"
#include "BloqueGeneral.h"
#include "Publicador.h"

// Sets default values
ABloqueObedece::ABloqueObedece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABloqueObedece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloqueObedece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ABloqueObedece::Destroyed()
{
	Super::Destroyed();
	//Log Error if its Clock Tower is NULL
	if (!Senalador) {
	UE_LOG(LogTemp, Error, TEXT("Destroyed():ClockTower is NULL, make sure it's initialized.")); return; }
	//Unsubscribe from the Clock Tower if it's destroyed
	Senalador->Desuscribirse(this);
}

void ABloqueObedece::Actualizar(APublicador* Publicador)
{
	//Execute the routine
	Cambios();

}

void ABloqueObedece::Cambios()
{
	//Log Error if its Clock Tower is NULL
	if (!Senalador) {
		UE_LOG(LogTemp, Error, TEXT("Morph():ClockTower is NULL, make sure it's initialized.")); return; }
	//Get the current time of the Clock Tower
		FString Estado = Senalador->GetEstado();
		if (!Estado.Compare("Estado1"))
		{
			//Execute the Morning routine
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Estamos en el estado %s"),*Estado));
		}
		else if (!Estado.Compare("Estado2"))
		{
			//Execute the Midday routine
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("2Estamos en el estado %s"),*Estado));
			ABloqueGeneral* BloqueGeneral = GetWorld()->SpawnActor<ABloqueGeneral>(FVector(150,200,300),FRotator::ZeroRotator);

		}
		else if (!Estado.Compare("Estado3"))
		{
			//Execute the Evening routine
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("3Estamos en el estado %s"),*Estado));
		}

}

void ABloqueObedece::DefinirSenalador(ASenalador* mySenalador)
{
	//Log Error if the passed Clock Tower is NULL
	if (!mySenalador) {
		UE_LOG(LogTemp, Error,TEXT("SetClockTower(): myClockTower is NULL, make sure it's initialized.")); return; }
	//Set the Clock Tower and Subscribe to that
	Senalador = mySenalador;
	Senalador->Suscribirse(this);

}

