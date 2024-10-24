// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/CapsuleComponent.h"
#include "Components/PlayerStateComponent.h"

using PlayerState = UPlayerStateComponent::State;

APlayerCharacter::APlayerCharacter()
{
	bUseControllerRotationYaw = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraBoom->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	FollowCamera->SetupAttachment(CameraBoom);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));

	State = CreateDefaultSubobject<UPlayerStateComponent>(TEXT("State"));
}

void APlayerCharacter::BeginPlay() {
	Super::BeginPlay();
	
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);

	EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &APlayerCharacter::Run);
	EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &APlayerCharacter::Run);

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APlayerCharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &APlayerCharacter::StopJumping);

	EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Interact);
	// EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &APlayerCharacter::Interact);
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	const FVector ForwardDirection = FVector(1, 0, 0); // X축 방향으로의 이동
	const FVector RightDirection = FVector(0, 1, 0); // Y축 방향으로의 이동

	AddMovementInput(ForwardDirection, MovementVector.X);
	AddMovementInput(RightDirection, MovementVector.Y);

	if(MovementVector != FVector2D::ZeroVector)
		State->SetPlayerState(PlayerState::Walk);
	else
		State->SetPlayerState(PlayerState::Idle);
	
}

void APlayerCharacter::Run(const FInputActionValue& Value)
{
	bool bIsRunning = Value.Get<bool>();
	GetCharacterMovement()->MaxWalkSpeed = bIsRunning ? 600.f : 300.f;
	
	if(GetMovementComponent()->Velocity == FVector::ZeroVector)
		State->SetPlayerState(PlayerState::Idle);
	else {
		if(bIsRunning) {
			State->SetPlayerState(PlayerState::Run);
		}
		else {
			State->SetPlayerState(PlayerState::Walk);
		}
	}
}

void APlayerCharacter::Interact(const FInputActionValue& Value)
{
	const FVector Start = GetActorLocation();
	const FVector End = Start + GetActorForwardVector() * 100.f;
	
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_EngineTraceChannel3));

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	FHitResult HitResult;
	UKismetSystemLibrary::LineTraceSingleForObjects(
		GetWorld(),
		Start,
		End,
		ObjectTypes,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,
		HitResult,
		true
	);

	AActor* HitActor = HitResult.GetActor();
	if (HitActor)
	{
		UE_LOG(LogTemp, Log, TEXT("Hit Actor: %s"), *HitActor->GetName());
	}
}
