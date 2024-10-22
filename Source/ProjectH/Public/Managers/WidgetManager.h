// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WidgetManager.generated.h"

class UPopupBase;

/**
 * 
 */
UCLASS()
class PROJECTH_API UWidgetManager : public UObject
{
	GENERATED_BODY()
	UWidgetManager();


public:
	inline const TObjectPtr<UPopupBase> GetPopupWidget() {
		return PopupWidgets;
	}

private:
	UPROPERTY()
	TObjectPtr<UPopupBase> PopupWidgets;
};
