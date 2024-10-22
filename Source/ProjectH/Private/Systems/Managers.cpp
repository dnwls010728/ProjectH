// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/Managers.h"
#include "Engine/World.h"

Managers::Managers() {

}

Managers::~Managers() {

}

void Managers::InitPlay() {
	Widget = NewObject<UWidgetManager>();
}
