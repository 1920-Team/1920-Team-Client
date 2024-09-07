// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "GameInfoInstance.generated.h"


USTRUCT(BlueprintType)
struct FServerData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString Name;
	UPROPERTY(BlueprintReadWrite)
	int32 CurrentPlayers;
	UPROPERTY(BlueprintReadWrite)
	int32 MaxPlayers;
	UPROPERTY(BlueprintReadWrite)
	FString HostUserName;
};

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
	void HostSession(int32 PublicConnections, bool UseLAN, bool UseLobbiesifAvailable, FString ServerName);

	UFUNCTION(BlueprintCallable, Category = "SessionInteraciton")
	void FindSession(bool UseLAN);

	UFUNCTION(BlueprintCallable, Category = "SessionInteraciton")
	void JoinSession(int32 Index);

	UFUNCTION(BlueprintImplementableEvent, Category = "SessionInteraction")
	void OnSessionsFound(const TArray<FServerData>& SessionInfos);

private:
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;
	TArray<FServerData> ServerDatas;

	void OnCreateSessionComplete(FName SessionName, bool Success);
	void OnDestroySessionComplete(FName SessionName, bool Success);
	void OnFindSessionsComplete(bool Success);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	void CreateSession();

	int32 PublicConnections;
	bool UseLAN;
	bool UseLobbiesifAvailable;
	FString ServerName;
	
};
