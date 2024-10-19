// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DefaultPlayerController.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ADefaultPlayerController::ADefaultPlayerController()
{
}

void ADefaultPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (InputMappingContext)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		if (IsValid(Subsystem))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}

void ADefaultPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
}
