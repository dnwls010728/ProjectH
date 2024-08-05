// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AUser;

class PROJECTH_API GameManager
{
public:
	GameManager();
	~GameManager();

public:
	UPROPERTY()
	TObjectPtr<AUser> Player;

};
