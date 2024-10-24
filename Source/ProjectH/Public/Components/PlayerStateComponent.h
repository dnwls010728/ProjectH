// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStateComponent.generated.h"

UENUM()
enum class State {
	Idle,
	Run,
	Walk,
	Contacting,
	Holding,
	Climbing
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTH_API UPlayerStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPlayerStateComponent();

	inline const State& GetPlayerState() const {
		return PState;
	}

	void SetPlayerState(const State& newState);



protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere)
	State PState;
};
