// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Libro/Potion.h"
#include "PotionShop.generated.h"

UCLASS()
class TETRIS_UE4_API APotionShop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APotionShop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual APotion* ConcoctPotion(FString PotionSKU)PURE_VIRTUAL(APotionShop::ConcoctPotion, return nullptr;);
	//Order, concoct and returns a Potion of a specific Category
	APotion* OrderPotion(FString Category);


};
