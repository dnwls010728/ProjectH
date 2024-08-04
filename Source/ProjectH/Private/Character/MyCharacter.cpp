// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MyCharacter.h"

#include "AbilitySystemComponent.h"
#include "MyPlayerState.h"

AMyCharacter::AMyCharacter()
{
	ASC = nullptr;
}

void AMyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AMyPlayerState* PS = GetPlayerState<AMyPlayerState>();
	if (PS)
	{
		ASC = PS->GetAbilitySystemComponent();
		ASC->InitAbilityActorInfo(PS, this);
	}
	
}

UAbilitySystemComponent* AMyCharacter::GetAbilitySystemComponent() const
{
	return ASC;
}
