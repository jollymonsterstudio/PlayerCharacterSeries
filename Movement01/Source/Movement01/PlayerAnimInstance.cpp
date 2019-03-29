// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAnimInstance.h"

#include "Movement01Character.h"
#include "GameFramework/PawnMovementComponent.h"

#include "Engine.h"

UPlayerAnimInstance::UPlayerAnimInstance()
{
	bIsInAir = false;
	bIsAnimationBlended = true;
	Speed = 0.f;
}

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// cache the pawn
	Owner = TryGetPawnOwner();
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
	Super::NativeUpdateAnimation(DeltaTimeX);

	// double check our pointers make sure nothing is empty
	if (!Owner)
	{
		return;
	}

	if (Owner->IsA(AMovement01Character::StaticClass()))
	{
		AMovement01Character* PlayerCharacter = Cast<AMovement01Character>(Owner);
		// again check pointers
		if (PlayerCharacter)
		{
			bIsInAir = PlayerCharacter->GetMovementComponent()->IsFalling();
			bIsAnimationBlended = PlayerCharacter->IsAnimationBlended();
			Speed = PlayerCharacter->GetVelocity().Size();
			bIsCrouching = PlayerCharacter->GetMovementComponent()->IsCrouching();
			bIsArmed = PlayerCharacter->IsArmed();
			bIsMoving = Speed > 0 ? true : false;
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "IsInAir: " + FString(IsInAir ? "true" : "false"));
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "IsAnimationBlended: " + FString(IsAnimationBlended ? "true" : "false"));
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "Speed: " + FString::SanitizeFloat(Speed));
		}
	}
}