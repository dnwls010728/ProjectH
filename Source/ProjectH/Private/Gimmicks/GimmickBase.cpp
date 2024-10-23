// Fill out your copyright notice in the Description page of Project Settings.


#include "Gimmicks/GimmickBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGimmickBase::AGimmickBase()
	:Type_(GimmickTypes::None)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Capsule->SetCollisionProfileName(FName(TEXT("Interactable")));
	Capsule->SetSimulatePhysics(true);
	
	
	RootComponent = Capsule;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionProfileName(FName(TEXT("Interactable")));

}

// Called when the game starts or when spawned
void AGimmickBase::BeginPlay()
{
	Super::BeginPlay();
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &AGimmickBase::OnOverlap);
}

// Called every frame
void AGimmickBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGimmickBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	GetWorld()->DestroyActor(this);
}

