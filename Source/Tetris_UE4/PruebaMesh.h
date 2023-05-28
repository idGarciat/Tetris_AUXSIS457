// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PruebaMesh.generated.h"

UCLASS()
class TETRIS_UE4_API APruebaMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APruebaMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Prueba_Mesh;


	FORCEINLINE class UStaticMeshComponent* GetPrueba_Mesh() const { return Prueba_Mesh; }
	FORCEINLINE void SetPrueba_Mesht(class UStaticMeshComponent* _Prueba_Mesh) { Prueba_Mesh = _Prueba_Mesh; }

};
