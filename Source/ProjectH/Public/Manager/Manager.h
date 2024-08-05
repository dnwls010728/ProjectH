// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameManager.h"
#include <memory>
#include "Subsystems/EngineSubsystem.h"
#include "Manager.generated.h"

class UWorld;

UCLASS()
class PROJECTH_API UManager : public UEngineSubsystem
{
	GENERATED_BODY()
	
public:
	void BeginPlay(UWorld* world);

	std::shared_ptr<GameManager> Game;


private:
	UPROPERTY()
	TObjectPtr<UWorld> World;
};
