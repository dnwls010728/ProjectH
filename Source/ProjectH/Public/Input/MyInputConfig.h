// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "MyInputConfig.generated.h"

USTRUCT(BlueprintType)
struct FMyInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
	
};

/**
 * 
 */
UCLASS()
class PROJECTH_API UMyInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag) const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FMyInputAction> AbilityInputActions;
	
};
