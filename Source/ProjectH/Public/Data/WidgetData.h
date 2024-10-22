// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WidgetData.generated.h"

class UWidgetBase;

/**
 * 
 */
UCLASS()
class PROJECTH_API UWidgetData : public UDataTable
{
	GENERATED_BODY()
	
};


USTRUCT(BlueprintType)
struct PROJECTH_API FWidgetTableRow : public FTableRowBase {
	GENERATED_BODY()

public:
	

};