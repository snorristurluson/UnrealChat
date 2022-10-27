// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ServerSideCheatsComponent.h"
#include "UObject/Object.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHAT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UServerSideCheatsComponent* ServerSideCheats;
	
public:
	AMyPlayerController();
	
	virtual void PostInitializeComponents() override;
	virtual void EnableCheats() override;

};
