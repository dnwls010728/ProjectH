// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movable.generated.h"

UCLASS()
class PROJECTH_API AMovable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	TArray<FTransform> PushTransforms;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
