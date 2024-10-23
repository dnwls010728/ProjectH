// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Data/WidgetAssets.h"
#include "WidgetManager.generated.h"

class UWidgetBase;

/**
 * 
 */
UCLASS()
class PROJECTH_API UWidgetManager : public UObject
{
	GENERATED_BODY()
	UWidgetManager();


public:
	inline const TMap<FString, TObjectPtr<UWidgetBase>> GetPopupWidget() {
		return PopupWidgets->Widgets;
	}

private:
	UPROPERTY()
	TObjectPtr<UWidgetAssets> PopupWidgets;
	
};
