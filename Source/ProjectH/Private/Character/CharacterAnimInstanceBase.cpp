// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterAnimInstanceBase.h"

#include "Character/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCharacterAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<ACharacterBase>(TryGetPawnOwner());
	if (IsValid(Character))
	{
		MovementComponent = Character->GetCharacterMovement();
	}
}

void UCharacterAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(MovementComponent))
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(MovementComponent->Velocity);
		bIsFalling = MovementComponent->IsFalling();
	}
}
