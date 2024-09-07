// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInfoInstance.h"

#include "OnlineSessionSettings.h"


const static FName SESSION_NAME = TEXT("My Session Game");
const static FName SERVER_NAME_SETTINGS_KEY = TEXT("ServerName");


void UGameInfoInstance::Init()
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Found subsystem %s"), *Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found no subsystem"));
	}
}

void UGameInfoInstance::CreateSessionByName(class APlayerController* PlayerController, int32 PublicConnections, bool UseLAN, bool UseLobbiesifAvailable, FString ServerName)
{
	FOnlineSessionSettings SessionSettings;

	if (UseLAN)
	{
		SessionSettings.bIsLANMatch = true;
	}
	else
	{
		SessionSettings.bIsLANMatch = false;
	}

	SessionSettings.NumPublicConnections = PublicConnections;
	SessionSettings.bShouldAdvertise = UseLobbiesifAvailable;
	SessionSettings.bUsesPresence = true;
	SessionSettings.Set(SERVER_NAME_SETTINGS_KEY, ServerName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	SessionInterface->CreateSession(0, SESSION_NAME, SessionSettings);
}