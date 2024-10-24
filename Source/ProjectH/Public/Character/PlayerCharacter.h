// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "PlayerCharacter.generated.h"

class UInputAction;
struct FInputActionValue;
class UPlayerStateComponent;
/**
 * 
 */
UCLASS()
class PROJECTH_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	inline const TObjectPtr<UPlayerStateComponent> GetStateComponent() const {
		return State;
	}

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCameraComponent> FollowCamera;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> RunAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> InteractAction;
	
	void Move(const FInputActionValue& Value);
	void Run(const FInputActionValue& Value);
	void Interact(const FInputActionValue& Value);
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPlayerStateComponent> State;

	UPROPERTY()
	bool bIsRunning;
};
