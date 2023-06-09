// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/ConcreteEnemy.h"

void AConcreteEnemy::Fight()
{
    //Call the parent Fight function and log a message
    Super::Fight();
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Pelea del concrete"));
}

int AConcreteEnemy::GetDamage()
{
    //Returns the base Damage + 5
    return Super::GetDamage() + 5;
}

void AConcreteEnemy::Die()
{
    Super::Die();
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("El concrete enemy muere"));
}

void AConcreteEnemy::SetEnemy(AActor* ConcreteEnemy)
{

}
