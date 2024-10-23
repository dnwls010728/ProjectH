// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RepeatGimmicks.generated.h"

class ARepeatBase;

/**
 * 
 */
UCLASS()
class PROJECTH_API URepeatGimmicks : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, TObjectPtr<ARepeatBase>> Gimmicks;
};
