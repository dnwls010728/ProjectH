// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GimmickBase.generated.h"

class UCapsuleComponent;

UCLASS()
class PROJECTH_API AGimmickBase : public AActor
{
	GENERATED_BODY()
public:
	enum class GimmickTypes {
		None,
		Repeat,
		Nightmare,
		Object,
	};
	
public:	
	// Sets default values for this actor's properties
	AGimmickBase();

	inline const GimmickTypes& GetType() {
		return Type_;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY()
	TObjectPtr<UCapsuleComponent> Capsule;


	GimmickTypes Type_;



};
