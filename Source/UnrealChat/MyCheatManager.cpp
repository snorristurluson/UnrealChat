// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCheatManager.h"

UServerSideCheatsComponent* UMyCheatManager::GetServerSideCheats() const
{
	return Cast<UServerSideCheatsComponent>(
		GetPlayerController()->GetComponentByClass(UServerSideCheatsComponent::StaticClass()));
}

void UMyCheatManager::Bingo()
{
	GetServerSideCheats()->Bingo();
}
