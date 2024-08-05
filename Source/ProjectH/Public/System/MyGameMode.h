// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Manager/Manager.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

UCLASS()
class PROJECTH_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()
	inline static AMyGameMode* Instance = nullptr;

public:
	AMyGameMode();
	static UManager* GetManager() { return Instance->Manager; }

protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<UManager> Manager;
};

#define Managers AMyGameMode::GetManager()