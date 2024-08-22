// Fill out your copyright notice in the Description page of Project Settings.


#include "SessionHelper.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

FString USessionHelper::GetSessionIPAddress()
{
    IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
    if (OnlineSubsystem)
    {
        IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
        if (SessionInterface.IsValid())
        {
            FNamedOnlineSession* Session = SessionInterface->GetNamedSession(NAME_GameSession);
            if (Session)
            {
                FString Address;
                SessionInterface->GetResolvedConnectString(NAME_GameSession, Address);
                return Address;
            }
        }
    }
    return FString("No Session Found");
}