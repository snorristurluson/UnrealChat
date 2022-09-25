// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatClient.h"

#include "ChatServer.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerState.h"

DECLARE_LOG_CATEGORY_CLASS(LogChatClient, Display, Display)

UChatClient::UChatClient()
{
	SetIsReplicatedByDefault(true);
}

void UChatClient::Send_Implementation(const FText& Message)
{
	if (!ChatServer)
	{
		AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
		if (GameMode)
		{
			ChatServer = Cast<UChatServer>(GameMode->GetComponentByClass(UChatServer::StaticClass()));
		}
		else
		{
			UE_LOG(LogChatClient, Warning, TEXT("No game mode found"));
			ChatServer = nullptr;
		}
		if (!ChatServer)
		{
			UE_LOG(LogChatClient, Warning, TEXT("No chat server established"));
			return;
		}
	}
	if (!PlayerState)
	{
		PlayerState = Cast<APlayerController>(GetOwner())->GetPlayerState<APlayerState>();
		if (PlayerState)
		{
			MyName = FText::FromString(PlayerState->GetPlayerName());
		}
	}
	ChatServer->Send(MyName, Message);
}

void UChatClient::Receive_Implementation(const FText& From, const FText& Message)
{
	OnMessageReceived.Broadcast(From, Message);
}
