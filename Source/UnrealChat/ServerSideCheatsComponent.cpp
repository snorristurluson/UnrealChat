// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerSideCheatsComponent.h"


UServerSideCheatsComponent::UServerSideCheatsComponent()
{
	SetIsReplicatedByDefault(true);
}

void UServerSideCheatsComponent::Bingo_Implementation()
{
	if (GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Display, TEXT("Bongo on the server!"));
	}
}
