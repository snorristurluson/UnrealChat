// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealChatGameMode.h"
#include "UnrealChatCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealChatGameMode::AUnrealChatGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	ChatServer = CreateDefaultSubobject<UChatServer>(TEXT("ChatServer"));
}
