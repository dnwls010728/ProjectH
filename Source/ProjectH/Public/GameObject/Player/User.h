// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Base/GameObject.h"
#include "User.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTH_API AUser : public AGameObject
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
};
