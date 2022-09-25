// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ChatServer.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealChatGameMode.generated.h"

UCLASS(minimalapi)
class AUnrealChatGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealChatGameMode();

protected:
	UPROPERTY(BlueprintReadOnly)
	UChatServer* ChatServer;
};



