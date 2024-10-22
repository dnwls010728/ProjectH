// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WidgetAssets.generated.h"

class UWidgetBase;

/**
 * 
 */
UCLASS()
class PROJECTH_API UWidgetAssets : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TMap<FString, TObjectPtr<UWidgetBase>> Widgets;
};
