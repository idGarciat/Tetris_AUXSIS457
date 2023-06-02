// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Libro/StarShipCrewMember.h"
#include "StarShipFacade.generated.h"

UCLASS()
class TETRIS_UE4_API AStarShipFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStarShipFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	//The Crew list
	TArray<AStarShipCrewMember*> Crew;
	//The Tasks to execute
	UPROPERTY()
		TArray<FString> Tasks;

private:
	//Execute the tasks for a specific Crew
	void PerformTasks(TArray<AStarShipCrewMember*> myCrew,TArray<FString> myTasks);

public:
	//Execute the Reveille tasks
	void Reveille();
	//Execute the PlanOfTheDay tasks
	void PlanOfTheDay();
	//Execute the Taps tasks
	void Taps();


};
