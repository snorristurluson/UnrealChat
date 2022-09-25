#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChatServer.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UNREALCHAT_API UChatServer : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Send(const FText& From, const FText& Message);

};
