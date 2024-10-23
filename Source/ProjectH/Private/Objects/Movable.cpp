// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/Movable.h"

// Sets default values
AMovable::AMovable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

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

