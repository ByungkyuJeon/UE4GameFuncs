// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4GameFuncsGameMode.h"
#include "UE4GameFuncsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4GameFuncsGameMode::AUE4GameFuncsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
