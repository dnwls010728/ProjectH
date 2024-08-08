// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/MyInputConfig.h"

const UInputAction* UMyInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag) const
{
	for (const FMyInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}
	
	return nullptr;
}
