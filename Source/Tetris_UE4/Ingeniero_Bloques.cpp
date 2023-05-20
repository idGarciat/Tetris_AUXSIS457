// Fill out your copyright notice in the Description page of Project Settings.


#include "Ingeniero_Bloques.h"

// Sets default values
AIngeniero_Bloques::AIngeniero_Bloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIngeniero_Bloques::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIngeniero_Bloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIngeniero_Bloques::ConstruirBloque()
{
	//Creates the buildings
	ConstructorBloque->ContruirTamanoBloque();
	ConstructorBloque->ConstruirColorBloque();
	ConstructorBloque->ConstruirMaterial();


}

void AIngeniero_Bloques::SetConstructorBloque(AActor* Constructor)
{
	ConstructorBloque = Cast<IConstructorBloque>(Constructor);
}

ABloqueGeneral* AIngeniero_Bloques::GetBloqueGeneral()
{
	if (ConstructorBloque)
	{
		//Returns the Lodging of the Builder
		return ConstructorBloque->GetBloqueGeneral();
	}

	
	return nullptr;

}

