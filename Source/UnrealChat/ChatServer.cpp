#include "ChatServer.h"

#include "ChatClient.h"


void UChatServer::Send_Implementation(const FText& From, const FText& Message)
{
	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		auto Client = Cast<UChatClient>((*It)->GetComponentByClass(UChatClient::StaticClass()));
		Client->Receive(From, Message);
	}
}
