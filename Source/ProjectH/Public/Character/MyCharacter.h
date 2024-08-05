// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MyCharacterBase.h"
#include "MyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTH_API AMyCharacter : public AMyCharacterBase
{
	GENERATED_BODY()

public:
	AMyCharacter();

	virtual void PossessedBy(AController* NewController) override;
	
};
