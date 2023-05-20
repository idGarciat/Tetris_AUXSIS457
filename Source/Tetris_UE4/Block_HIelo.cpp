// Fill out your copyright notice in the Description page of Project Settings.


#include "Block_HIelo.h"

void ABlock_HIelo::BeginPlay()
{
	BloqueGeneral = GetWorld()->SpawnActor<ABloqueGeneral>
		(ABloqueGeneral::StaticClass());
	//Attach it to the Builder (this)
	BloqueGeneral->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	NewMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/Mesh/NewMaterial.NewMaterial'")));
}

void ABlock_HIelo::ContruirTamanoBloque()
{
	
	BloqueGeneral->SetTamanoBloque("El tamaño del bloque de Hielo");
}

void ABlock_HIelo::ConstruirColorBloque()
{
	BloqueGeneral->SetColorBloque("El color del bloque de Hielo");
}

void ABlock_HIelo::ConstruirMaterial()
{
	BloqueGeneral->SetMaterial("El material del bloque de Hielo");

	FString MaterialName = NewMaterial->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El material es %s"), *MaterialName));
}

ABloqueGeneral* ABlock_HIelo::GetBloqueGeneral()
{
	return BloqueGeneral;
}
