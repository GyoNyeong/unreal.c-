// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyMyCppPawn.h"
AMyPlayerController::AMyPlayerController()
{

}


void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//jumpdelegate.AddDynamic(this,&AMyPlayerController::Jump);

	if (UEnhancedInputComponent* InputCom = Cast<UEnhancedInputComponent>(InputComponent))
	{
		InputCom->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AMyPlayerController::Look);
		InputCom->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
		InputCom->BindAction(IA_Interaction, ETriggerEvent::Completed, this, &AMyPlayerController::Interaction);
		InputCom->BindAction(IA_Jump, ETriggerEvent::Started, this, &AMyPlayerController::Jump);
		InputCom->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AMyPlayerController::stopjump);
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

	FVector2D A = Value.Get<FVector2D>();
	AddYawInput(A.X);
	AddPitchInput(A.Y);
}

void AMyPlayerController::Move(const FInputActionValue& Value)
{
	
	FVector2D M = Value.Get<FVector2D>();
	//float MF = F.X * Multiplier;
	//FVector MV = MF * GetPawn()->GetActorRightVector();
	//GetPawn()->AddMovementInput(MV);
	//float MW = F.Y * Multiplier;
	//FVector MWW = MW * GetPawn()->GetActorForwardVector();
	//GetPawn()->AddMovementInput(MWW);

	FRotator F = GetControlRotation();
	const FRotator YawRotation(0, F.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// add movement 
	
	GetPawn()->AddMovementInput(ForwardDirection, M.Y);
	GetPawn()->AddMovementInput(RightDirection, M.X); 


};

void AMyPlayerController::Interaction(const FInputActionValue& Value)
{
	AMyMyCppPawn* myPawn = Cast<AMyMyCppPawn>(GetPawn());
	if (myPawn)
	{
		Possess(myPawn->overlappingpawn);
		/*jumpdelegate.AddDynamic(myPawn, &AMyMyCppPawn::Jump);*/
	}
	
}

void AMyPlayerController::Jump()
{
	//jumpdelegate.Broadcast();
	/*GetPawn()->AddActorWorldOffset(FVector(0.0f, 0.0f, 500.0f), false);*/
	jumpdelegate.Broadcast();

	//GetPawn()->AddActorWorldOffset(FVector(0.0f, 0.0f, -500.0f), false); StopJump
	
}

void AMyPlayerController::stopjump()
{
	/*GetPawn()->AddActorWorldOffset(FVector(0.0f, 0.0f, -500.0f), false);*/
	Sjumpdelegate.Broadcast();
}
