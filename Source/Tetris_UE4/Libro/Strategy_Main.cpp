// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/Strategy_Main.h"
#include "Libro/BattleShip.h"
#include "Libro/BruteForceStrategy.h"
#include "Libro/DivideConquerStrategy.h"
#include "Libro/RetreatStrategy.h"


// Sets default values
AStrategy_Main::AStrategy_Main()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategy_Main::BeginPlay()
{
	Super::BeginPlay();
	
	//Enemies alert log
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("A tiny frigate wants some trouble"));
	//Spawn the Battle Ship
	ABattleShip* BattleShip = GetWorld()->SpawnActor<ABattleShip>(ABattleShip::StaticClass());

	//Spawn de las distintas estrategias
	ABruteForceStrategy* BruteForceStrategy = GetWorld() -> SpawnActor<ABruteForceStrategy>(ABruteForceStrategy::StaticClass());
	ARetreatStrategy* RetreatStrategy = GetWorld()->SpawnActor<ARetreatStrategy>(ARetreatStrategy::StaticClass());
	ADivideConquerStrategy* DivideConquerStrategy = GetWorld()->SpawnActor<ADivideConquerStrategy>(ADivideConquerStrategy::StaticClass());
	
	
	BattleShip->AlterManeuvers(RetreatStrategy);
	//Engage with the current Strategy
	BattleShip->Engage();
	//Enemies alert log
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Four tiny frigates want some trouble"));

	BattleShip->AlterManeuvers(BruteForceStrategy);
	//Engage with the current Strategy
	BattleShip->Engage();
	//Enemies alert log
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("An aircraft carrier group wants some trouble"));

	BattleShip->AlterManeuvers(DivideConquerStrategy);
	//Engage with the current Strategy
	BattleShip->Engage();



}

// Called every frame
void AStrategy_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

