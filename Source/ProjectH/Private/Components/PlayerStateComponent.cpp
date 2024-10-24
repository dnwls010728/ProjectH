// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PlayerStateComponent.h"

// Sets default values for this component's properties
UPlayerStateComponent::UPlayerStateComponent() 
	: PState(EState::Idle)
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UPlayerStateComponent::SetPlayerState(const EState& newState) {
	PState = newState;
}


// Called when the game starts
void UPlayerStateComponent::BeginPlay()
{
	Super::BeginPlay();

	
	
}