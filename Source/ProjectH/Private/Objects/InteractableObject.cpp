// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/InteractableObject.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Systems/GMB.h"
#include "Widgets/Popup/PopupBase.h"

// Sets default values
AInteractableObject::AInteractableObject()
	: PType(PassingType::None)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);
}

// Called when the game starts or when spawned
void AInteractableObject::BeginPlay()
{
	Super::BeginPlay();
	
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &AInteractableObject::OnOverlap);
	Capsule->OnComponentHit.AddDynamic(this, &AInteractableObject::OnHit);

	switch(PType) {
	case PassingType::Passable:
	{
		Mesh->SetCollisionProfileName(FName(TEXT("BlockAll")));
		Capsule->SetCollisionProfileName(FName(TEXT("Passable")));
	}
	case PassingType::NonPassable:
	{
		Mesh->SetCollisionProfileName(FName(TEXT("BlockAll")));
		Capsule->SetCollisionProfileName(FName(TEXT("NonPassable")));
	}
	}
}

// Called every frame
void AInteractableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AInteractableObject::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	
}

void AInteractableObject::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {

}

