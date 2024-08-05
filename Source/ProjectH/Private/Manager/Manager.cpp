// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/Manager.h"

void UManager::BeginPlay(UWorld* world)
{
	World = world;
	Game = std::make_shared<GameManager>();
}
