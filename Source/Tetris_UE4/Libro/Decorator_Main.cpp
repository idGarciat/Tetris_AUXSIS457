// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/Decorator_Main.h"
#include "Libro/MeleeEnemy.h"
#include "Libro/ProjectileEnemy.h"
#include "Libro/ConcreteEnemy.h"
#include "Libro/Enemy.h"

// Sets default values
ADecorator_Main::ADecorator_Main()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecorator_Main::BeginPlay()
{
	Super::BeginPlay();
	
	//Spawn a Concrete Enemy
	AConcreteEnemy* ConcreteEnemy = GetWorld() -> SpawnActor<AConcreteEnemy>(AConcreteEnemy::StaticClass());
	//Spawn a Melee Enemy and set its Enemy to the Concrete one
	AMeleeEnemy* MeleeEnemy = GetWorld() -> SpawnActor<AMeleeEnemy>(AMeleeEnemy::StaticClass());
	MeleeEnemy->SetEnemy(ConcreteEnemy);
	//Spawn a Projectile Enemy and set its Enemy to the Melee one
	AProjectileEnemy* ProjectileEnemy = GetWorld() -> SpawnActor<AProjectileEnemy>(AProjectileEnemy::StaticClass());
	ProjectileEnemy->SetEnemy(MeleeEnemy);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Enemigos Melees apareciendo"));
	Enemy = MeleeEnemy;
	Enemy->Fight();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Enemigos Melee haciendo %i dano"), Enemy -> GetDamage()));
	Enemy->Die();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Enemigos ahora armados con pistolas"));
	Enemy = ProjectileEnemy;
	Enemy->Fight();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Los proyectiles hacen %i dano."), Enemy -> GetDamage()));
	Enemy->Die();

}

// Called every frame
void ADecorator_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

