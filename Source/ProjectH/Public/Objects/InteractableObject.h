// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableObject.generated.h"

class UCapsuleComponent;
class UStaticMeshComponent;
class APlayerCharacter;

UCLASS()
class PROJECTH_API AInteractableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	enum class PassingType {
		None,
		Passable,
		NonPassable,
	};
	// Sets default values for this actor's properties
	AInteractableObject();

	virtual void Interact(TObjectPtr<APlayerCharacter> player) {
	};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	PassingType PType;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );
	
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
