// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UE_LOG(LogTemp, Display, TEXT("SetCalled"));
	if (UEnhancedInputComponent* InputCom = Cast<UEnhancedInputComponent>(InputComponent))
	{
		InputCom->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AMyPlayerController::Look);
		InputCom->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
		InputCom->BindAction(IA_Interaction, ETriggerEvent::Completed, this, &AMyPlayerController::Interaction);
		InputCom->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AMyPlayerController::Jump);
	}

}

void AMyPlayerController::BeginPlay()
{
	
	if (IMC)
	{
		
		UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		if (InputSubsystem)
		{
			InputSubsystem->AddMappingContext(IMC, 0);
		}
	}


}

void AMyPlayerController::Look(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Display, TEXT("LookCalled"));
	FVector2D A = Value.Get<FVector2D>();
	AddYawInput(A.X);
	AddPitchInput(A.Y);
}

void AMyPlayerController::Move(const FInputActionValue& Value)
{
	
	FVector2D F = Value.Get<FVector2D>();
	float MF = F.X * Multiplier;
	FVector MV = MF * GetPawn()->GetActorRightVector();
	GetPawn()->AddMovementInput(MV);
	float MW = F.Y * Multiplier;
	FVector MWW = MW * GetPawn()->GetActorForwardVector();
	GetPawn()->AddMovementInput(MWW);


};

void AMyPlayerController::Interaction(const FInputActionValue& Value)
{
	
}

void AMyPlayerController::Jump()
{

	GetPawn()->AddActorWorldOffset(FVector(0.0f, 0.0f, -500.0f), false);

	//GetPawn()->AddActorWorldOffset(FVector(0.0f, 0.0f, -500.0f), false); StopJump
	
}
