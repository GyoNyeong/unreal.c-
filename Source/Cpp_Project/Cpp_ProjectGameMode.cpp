// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cpp_ProjectGameMode.h"
#include "Cpp_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACpp_ProjectGameMode::ACpp_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
