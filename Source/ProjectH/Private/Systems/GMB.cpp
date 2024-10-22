// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/GMB.h"

AGMB* AGMB::Instance = nullptr;

void AGMB::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) {
	Super::InitGame(MapName, Options, ErrorMessage);
	
	Instance = this;
	auto mgr = AGMB::GetManager();
	mgr->SetWorld(GetWorld());
	mgr->InitPlay();
}

void AGMB::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	delete Instance->MGR;
}
