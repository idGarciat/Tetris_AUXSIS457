// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/HotelLodgingBuilder.h"
#include "Libro/Lodging.h"

// Sets default values
AHotelLodgingBuilder::AHotelLodgingBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHotelLodgingBuilder::BeginPlay()
{
	Super::BeginPlay();

	Lodging = GetWorld()->SpawnActor<ALodging>(ALodging::StaticClass());
	//Attach it to the Builder (this)
	Lodging->AttachToActor(this,
		FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called every frame
void AHotelLodgingBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHotelLodgingBuilder::BuildSwimmingPool()
{
	if (!Lodging) {
		UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
			//Set the Swimming Pool of the Lodging
	Lodging->SetSwimmingPool("Indoor Lagoon");

}

void AHotelLodgingBuilder::BuildLobbyArea()
{
	if (!Lodging) {
		UE_LOG(LogTemp, Error, TEXT("BuildLobbyArea():Lodging is NULL, make sure it's initialized.")); return; }
			//Set the Lobby Area of the Lodging
			Lodging->SetLobbyArea("Grand Hall");
}

void AHotelLodgingBuilder::BuildRestaurants()
{
	if (!Lodging) {
		UE_LOG(LogTemp, Error, TEXT("BuildRestaurants():Lodging is NULL, make sure it's initialized.")); return; }
			//Set the Restaurants of the Lodging
			Lodging->SetRestaurants("5 star Buffet");
}

void AHotelLodgingBuilder::BuildRooms()
{
	if (!Lodging) {
		UE_LOG(LogTemp, Error, TEXT("BuildRestaurants():Lodging is NULL, make sure it's initialized.")); return; }
			//Set the Restaurants of the Lodging
			Lodging->SetRestaurants("5 star Buffet");
}

ALodging* AHotelLodgingBuilder::GetLodging()
{
	return Lodging;

}

