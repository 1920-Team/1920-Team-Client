// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "GameInfoInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROTO1920_API UGameInfoInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init();

	UFUNCTION(BlueprintCallable, Category = "ServerSettings")
	void CreateSessionByName(class APlayerController* PlayerController, int32 PublicConnections, bool UseLAN, bool UseLobbiesifAvailable, FString ServerName);

private:
	IOnlineSessionPtr SessionInterface;
	
};
