// Fill out your copyright notice in the Description page of Project Settings.


#include "Block_Explosivo.h"

#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"

void ABlock_Explosivo::BeginPlay()
{
	// Spawn the Lodging Actors
		BloqueGeneral = GetWorld()->SpawnActor<ABloqueGeneral>
		(ABloqueGeneral::StaticClass());
	//Attach it to the Builder (this)
	BloqueGeneral->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
	UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	Material1 = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/Mesh/Material_005.Material_005'")));//Haciendo cast al material
}

void ABlock_Explosivo::ContruirTamanoBloque()
{
	//Set the Swimming Pool of the Lodging
	BloqueGeneral->SetTamanoBloque("El tamaño del bloque explosivo");

}

void ABlock_Explosivo::ConstruirColorBloque()
{
	BloqueGeneral->SetColorBloque("El color del bloque explosivo");

}

void ABlock_Explosivo::ConstruirMaterial()
{

	Mesh->SetMaterial(0, Material1);


	BloqueGeneral->SetMaterial("El Material del bloque explosivo");

	FString NombreMaterial = Material1->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El material es %s"), *NombreMaterial));



}

ABloqueGeneral* ABlock_Explosivo::GetBloqueGeneral()
{
	return BloqueGeneral;
}
