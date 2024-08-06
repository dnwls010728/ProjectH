// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MyPlayerController.h"
#include "GameObject/Player/User.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "Character/MyCharacter.h"
#include "Kismet/KismetMathLibrary.h"


AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(InputContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(InputContext, 0);
	User = Cast<AMyCharacter>(GetPawn());
	
	
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(Move, ETriggerEvent::Triggered, this, &AMyPlayerController::MoveFunc);
	EnhancedInputComponent->BindAction(Look, ETriggerEvent::Triggered, this, &AMyPlayerController::LookFunc);
}

void AMyPlayerController::MoveFunc(const FInputActionValue& value)
{
	FVector2D Dir = value.Get<FVector2D>();

	Dir.Normalize();
	Dir *= 50.0f;

	auto Movement = User->GetCharacterMovement();

	FRotator Rotation = GetControlRotation();
	FVector Forward = UKismetMathLibrary::GetForwardVector(Rotation);
	FVector Right = UKismetMathLibrary::GetRightVector(Rotation);

	FVector MoveToward = Forward * Dir.X + Right * Dir.Y;

	Movement->AddInputVector(MoveToward);

}

void AMyPlayerController::LookFunc(const FInputActionValue& value)
{
	FVector2D Dir = value.Get<FVector2D>();


	AddYawInput(Dir.X);
	AddPitchInput(-Dir.Y);
}