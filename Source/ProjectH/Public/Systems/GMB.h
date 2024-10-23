// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Managers.h"
#include "GameFramework/GameModeBase.h"
#include "GMB.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTH_API AGMB : public AGameModeBase
{
	GENERATED_BODY()
	static AGMB* Instance;
	AGMB();
protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
	
public:
	inline static Managers* GetManager() {
		if(Instance->MGR == nullptr) {
			Instance->MGR = new Managers;
		}
		return Instance->MGR;
	}

private:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

	Managers* MGR;
};

#define Managers AGMB::GetManager()