// Fill out your copyright notice in the Description page of Project Settings.


#include "System/MyGameMode.h"
#include "Manager/Manager.h"

AMyGameMode::AMyGameMode()
{
	Instance = this;
}

void AMyGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	Manager = GEngine->GetEngineSubsystem<UManager>();
	Manager->BeginPlay(GetWorld());

}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();

}
