// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MyCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "System/MyPlayerState.h"

AMyCharacter::AMyCharacter()
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->bUsePawnControlRotation = true;
}

void AMyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AMyPlayerState* MyPlayerState = GetPlayerState<AMyPlayerState>();
	check(MyPlayerState);

	AbilitySystemComponent = MyPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(MyPlayerState, this);

	AttributeSet = MyPlayerState->GetAttributeSet();
	
}
