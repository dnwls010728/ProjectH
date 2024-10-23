// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ObjectGimmicksAssets.generated.h"

class AObjectBase;

/**
 * 
 */
UCLASS()
class PROJECTH_API UObjectGimmicksAssets : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, TObjectPtr<AObjectBase>> Gimmicks;
};
