// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MyCharacterBase.h"

AMyCharacterBase::AMyCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* AMyCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AMyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
