// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/GMB.h"

AGMB* AGMB::Instance = nullptr;

AGMB::AGMB() {
	Instance = this;

}

void AGMB::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) {
	Super::InitGame(MapName, Options, ErrorMessage);
	Instance = this;
	auto mgr = AGMB::GetManager();
	mgr->InitPlay();
	mgr->SetWorld(GetWorld());

}

void AGMB::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	delete Instance->MGR;
}
