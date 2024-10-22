// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Managers/WidgetManager.h"

class UWorld;

/**
 * 
 */
class PROJECTH_API Managers
{
	Managers();
	~Managers();

public:
	UPROPERTY()
	TObjectPtr<UWidgetManager> Widget;


private:
	void InitPlay();
	inline void SetWorld(UWorld* world) {
		World_ = world;
	}

	UWorld* World_;
	friend class AGMB;
};
