// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Libro/LodgingBuilder.h"
#include "HotelLodgingBuilder.generated.h"


class ALodging;
UCLASS()
class TETRIS_UE4_API AHotelLodgingBuilder : public AActor, public ILodgingBuilder


{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHotelLodgingBuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere, Category = "Hotel Lodging")
	class ALodging* Lodging;


	//Create the Swimming Pool
	virtual void BuildSwimmingPool() override;
	//Create the Lobby Area
	virtual void BuildLobbyArea() override;
	//Create the Restaurants
	virtual void BuildRestaurants() override;
	//Create the Rooms
	virtual void BuildRooms() override;
	//Returns the Lodging
	virtual class ALodging* GetLodging() override;


};

