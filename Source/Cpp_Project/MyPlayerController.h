// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "MyPlayerController.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FJumpDelegate);

/**
 * 
 */
UCLASS()
class CPP_PROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	

public:

	AMyPlayerController();
	
	//FJumpDelegate jumpdelegate;

	virtual void SetupInputComponent() override;
	
	virtual void BeginPlay() override;

	UEnhancedInputComponent* MyInput;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInputMappingContext* IMC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* IA_Look;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* IA_Interaction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* IA_Jump;
	float Multiplier = 5;

	void Look(const FInputActionValue& Value);

	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void Interaction(const FInputActionValue& Value);

	UFUNCTION()
	void Jump();

	UFUNCTION()
	void stopjump();

};
