// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "SessionHelper.generated.h"


/**
 * 
 */
UCLASS()
class PROTO1920_API USessionHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Session")
	static FString GetSessionIPAddress();

};
