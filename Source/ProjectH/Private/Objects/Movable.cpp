// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/Movable.h"

#include "Components/ArrowComponent.h"

// Sets default values
AMovable::AMovable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

}

void AMovable::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	TArray<UArrowComponent*> ExistingArrows;
	GetComponents<UArrowComponent>(ExistingArrows);

	for (UArrowComponent* Arrow : ExistingArrows)
	{
		Arrow->DestroyComponent();
	}

	for (const auto& PushTransform : PushTransforms)
	{
		UArrowComponent* ArrowComponent = NewObject<UArrowComponent>(this);
		ArrowComponent->SetupAttachment(RootComponent);
		ArrowComponent->SetRelativeTransform(PushTransform);
		ArrowComponent->RegisterComponent();
	}
}

void AMovable::Hold()
{
}

// Called when the game starts or when spawned
void AMovable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

