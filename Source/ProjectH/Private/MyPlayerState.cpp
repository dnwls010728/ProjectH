// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"

#include "AbilitySystemComponent.h"

AMyPlayerState::AMyPlayerState()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
}

UAbilitySystemComponent* AMyPlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}
