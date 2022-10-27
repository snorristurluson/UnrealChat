// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ServerSideCheatsComponent.h"
#include "GameFramework/CheatManager.h"
#include "UObject/Object.h"
#include "MyCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHAT_API UMyCheatManager : public UCheatManager
{
	GENERATED_BODY()

	UServerSideCheatsComponent* GetServerSideCheats() const;

public:
	UFUNCTION(Exec)
	void Bingo();
};
