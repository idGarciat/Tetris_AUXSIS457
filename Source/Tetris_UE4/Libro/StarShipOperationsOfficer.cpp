// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/StarShipOperationsOfficer.h"

AStarShipOperationsOfficer::AStarShipOperationsOfficer()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void AStarShipOperationsOfficer::BeginPlay()
{
    Super::BeginPlay();
}

void AStarShipOperationsOfficer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AStarShipOperationsOfficer::Duty()
{
    // Print Duty string
     GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s synthesizes and disseminates incominginformation."),* CrewTitle()));

}

FString AStarShipOperationsOfficer::CrewTitle()
{
    //Return title
    return "The Operation Officer";
}
