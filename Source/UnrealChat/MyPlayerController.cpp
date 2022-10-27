// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
	ServerSideCheats = CreateDefaultSubobject<UServerSideCheatsComponent>(TEXT("ServerSideCheats"));
}

void AMyPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	EnableCheats();
}

void AMyPlayerController::EnableCheats()
{
	AddCheats(true);
}
