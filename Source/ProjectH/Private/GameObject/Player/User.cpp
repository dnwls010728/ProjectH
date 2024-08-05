// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Player/User.h"
#include "System/MyGameMode.h"
#include "GameFramework/CharacterMovementComponent.h"

void AUser::BeginPlay()
{
	Super::BeginPlay();
	Managers->Game->Player = this;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;

	GetCharacterMovement()->RotationRate = FRotator(800.0f, 0.0f, 0.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;
}
