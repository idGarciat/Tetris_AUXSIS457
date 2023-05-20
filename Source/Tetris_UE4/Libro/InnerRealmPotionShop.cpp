// Fill out your copyright notice in the Description page of Project Settings.


#include "Libro/InnerRealmPotionShop.h"
#include "Libro/InnerRealmHealthPotion.h"
#include "Libro/InnerRealmPowerPotion.h"
#include "Libro/InnerRealmSkillPotion.h"

APotion* AInnerRealmPotionShop::ConcoctPotion(FString PotionSKU)
{
	//Select which potion to spawn depending on the passed string
	if (PotionSKU.Equals("Health")) {
		return GetWorld()->SpawnActor<AInnerRealmHealthPotion>(AInnerRealmHealthPotion::StaticClass());
	}
	else if (PotionSKU.Equals("Power")) {
		return GetWorld()->SpawnActor<AInnerRealmPowerPotion>(AInnerRealmPowerPotion::StaticClass());
	}
	else if (PotionSKU.Equals("Skill")) {
		return GetWorld()->SpawnActor<AInnerRealmSkillPotion>(AInnerRealmSkillPotion::StaticClass());
	}
	else return nullptr; //Return null if the string isn't valid

}
