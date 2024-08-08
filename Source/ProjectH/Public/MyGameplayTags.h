// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
struct FMyGameplayTags
{
public:
 FORCEINLINE static const FMyGameplayTags& Get() { return GameplayTags; }
 
protected:
private:
 static FMyGameplayTags GameplayTags;
 
};
