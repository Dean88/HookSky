// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HookSkyGameMode.h"
#include "HookSkyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHookSkyGameMode::AHookSkyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Mannequin/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
