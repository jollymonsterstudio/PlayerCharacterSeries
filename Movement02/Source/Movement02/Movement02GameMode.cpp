// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Movement02GameMode.h"
#include "Movement02Character.h"
#include "UObject/ConstructorHelpers.h"

AMovement02GameMode::AMovement02GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
