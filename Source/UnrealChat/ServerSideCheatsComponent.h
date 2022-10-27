// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ServerSideCheatsComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UNREALCHAT_API UServerSideCheatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UServerSideCheatsComponent();

	UFUNCTION(BlueprintCallable, Server, Reliable, Category="Cheat Manager")
	virtual void Bingo();
};
