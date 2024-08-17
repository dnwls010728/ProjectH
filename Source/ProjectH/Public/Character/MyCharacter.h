// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MyCharacterBase.h"
#include "MyCharacter.generated.h"

struct FInputActionValue;
class UInputAction;
/**
 * 
 */
UCLASS()
class PROJECTH_API AMyCharacter : public AMyCharacterBase
{
	GENERATED_BODY()

public:
	AMyCharacter();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USpringArmComponent> CameraBoom;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UCameraComponent> FollowCamera;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> JumpAction;

	void Move(const FInputActionValue& Value);
	
};
