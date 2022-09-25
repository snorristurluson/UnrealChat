#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChatClient.generated.h"

class UChatServer;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMessageReceived, FText, From, FText, Message);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UNREALCHAT_API UChatClient : public UActorComponent
{
	GENERATED_BODY()

public:
	UChatClient();

	UFUNCTION(Client, Reliable)
	void Receive(const FText& From, const FText& Message);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Send(const FText& Message);
	
	UPROPERTY(BlueprintAssignable)
	FOnMessageReceived OnMessageReceived;

protected:
	UPROPERTY()
	UChatServer* ChatServer = nullptr;

	UPROPERTY()
	APlayerState* PlayerState = nullptr;
	
	FText MyName;};
