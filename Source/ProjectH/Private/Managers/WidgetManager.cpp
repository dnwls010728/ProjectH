// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/WidgetManager.h"
#include "Widgets/Popup/PopupBase.h"

UWidgetManager::UWidgetManager() {
	PopupWidgets = Cast<UPopupBase>(StaticLoadObject(UPopupBase::StaticClass(),
													 nullptr,
													 TEXT("/Script/ProjectH.WidgetAssets'/Game/Data/PopupWidgets.PopupWidgets'")));


}