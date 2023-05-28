// Fill out your copyright notice in the Description page of Project Settings.


#include "PruebaMesh.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APruebaMesh::APruebaMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PruebaMesh(TEXT("StaticMesh'/Game/Mesh/block.block'"));
	Prueba_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PruebaMesh"));
	RootComponent = Prueba_Mesh;
	Prueba_Mesh->SetStaticMesh(PruebaMesh.Object);
}

// Called when the game starts or when spawned
void APruebaMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APruebaMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

