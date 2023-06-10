// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/Gun.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::Fire()
{
	//Print Fire log
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("El arma esta disparando de la forma 1"));
}

void AGun::Fire2()
{
	//Print Fire log
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("El arma esta disparando de la forma 2"));

}

