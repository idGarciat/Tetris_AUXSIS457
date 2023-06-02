// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboGeneralFacade.h"

// Sets default values
ACuboGeneralFacade::ACuboGeneralFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Block Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockFinder(TEXT("StaticMesh'/Game/Mesh/block.block'"));
	RootComponent = Mesh;
	Mesh->SetStaticMesh(BlockFinder.Object);
	Material1 = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/Mesh/Material_3.Material_3'")));//Haciendo cast al material
	Material2 = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/Mesh/Material_6.Material_6'")));
}

// Called when the game starts or when spawned
void ACuboGeneralFacade::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void ACuboGeneralFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACuboGeneralFacade::Paralisis()
{
	// Print lights out string
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s El cubo se detuvo"),*NombreCubo()));

}

void ACuboGeneralFacade::Propulsion()
{
	// Print lights out string
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s El cubo esta preparandose para saltar"), *NombreCubo()));
	Mesh->SetMaterial(0, Material2);
}


void ACuboGeneralFacade::Camuflaje()
{
	// Print lights out string
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s El cubo se camufla"), *NombreCubo()));
	
	Mesh->SetMaterial(0, Material1);

}

void ACuboGeneralFacade::Accion(const FString& Accion)
{
	//Checks which task must be executed
	if (Accion.Equals("Camuflarse"))
	{
		//Camuflaje();
	}
	else if (Accion.Equals("Cambiar material"))
	{
		Camuflaje();
	}
	else if (Accion.Equals("Saltar"))
	{
		Propulsion();
	}
	else if (Accion.Equals("Tarea"))
	{
		Tarea();
	}
	else if (Accion.Equals("Tomar Propulsion"))
	{
		Propulsion();
	}
	else
	{
		//In case the passed Task doesn't exist
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,TEXT("Tarea sin definir"));
	}
}



void ACuboGeneralFacade::Accion(const TArray<FString>& Acciones)
{
	//Loop the Tasks array and call the Task() function for each of them
	for (const FString& myAccion : Acciones)
	{
		Accion(myAccion);
	}

}
