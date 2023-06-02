// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/StarShipSupplyOfficer.h"

AStarShipSupplyOfficer::AStarShipSupplyOfficer()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void AStarShipSupplyOfficer::BeginPlay()
{
    Super::BeginPlay();
}

void AStarShipSupplyOfficer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AStarShipSupplyOfficer::Duty()
{
    //Print Duty string
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s ensures there are ample ship supplies."),*CrewTitle()));
}

FString AStarShipSupplyOfficer::CrewTitle()
{
    //Return title
    return "The Navigation Officer";
}
