// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/WidgetManager.h"
#include "Data/WidgetAssets.h"

UWidgetManager::UWidgetManager() {
	PopupWidgets = Cast<UWidgetAssets>(StaticLoadObject(UWidgetAssets::StaticClass(),
													 nullptr,
													 TEXT("/Script/ProjectH.WidgetAssets'/Game/Data/PopupWidgets.PopupWidgets'")));


}