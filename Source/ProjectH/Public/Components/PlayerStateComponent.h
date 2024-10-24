// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objects/InteractableObject.h"
#include "Components/ActorComponent.h"
#include "PlayerStateComponent.generated.h"

UENUM()
enum class EState {
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

	inline const EState& GetPlayerState() const {
		return PState;
	}

	void SetPlayerState(const EState& newState);
	FORCEINLINE void AddContactObject(TObjectPtr<AInteractableObject> target) {
		Objects.Push(target);
	}

	FORCEINLINE void RemoveContactObject(TObjectPtr<AInteractableObject> target) {
		Objects.Remove(target);
	}

	FORCEINLINE TObjectPtr<AInteractableObject> GetLastContactObject() {
		if(Objects.Num() == 0) {
			return nullptr;
		}
		else {
			return Objects.Last();
		}
	}


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere)
	EState PState;

	TArray<TObjectPtr<AInteractableObject>> Objects;
};
