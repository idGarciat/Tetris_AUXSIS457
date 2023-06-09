// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/ProjectileEnemy.h"

void AProjectileEnemy::Fight()
{
    //Call the parent Fight function and log a message
    Super::Fight();
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Disparando de lejitos"));

}

int AProjectileEnemy::GetDamage()
{
    //Returns the base Damage + 5
    return Super::GetDamage() + 5;
}

void AProjectileEnemy::Die()
{
    //Call the parent Die function and log a message
    Super::Die();
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("El enemigo projectile muere"));
}

void AProjectileEnemy::SetEnemy(AActor* ConcreteEnemy)
{

}


