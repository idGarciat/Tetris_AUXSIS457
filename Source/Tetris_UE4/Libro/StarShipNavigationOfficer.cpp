// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/StarShipNavigationOfficer.h"

AStarShipNavigationOfficer::AStarShipNavigationOfficer()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

void AStarShipNavigationOfficer::BeginPlay()
{
    Super::BeginPlay();

}

void AStarShipNavigationOfficer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AStarShipNavigationOfficer::Duty()
{
    //Print Duty string
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s navigates the ship."),*CrewTitle()));
}

FString AStarShipNavigationOfficer::CrewTitle()
{
    //Return title
    return "The Navigation Officer";
}
