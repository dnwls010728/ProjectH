// Fill out your copyright notice in the Description page of Project Settings.


#include "Gimmicks/GimmickBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AGimmickBase::AGimmickBase()
	:Type_(GimmickTypes::None)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = Capsule;
}

// Called when the game starts or when spawned
void AGimmickBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGimmickBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

