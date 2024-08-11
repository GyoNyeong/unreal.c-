// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCppPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
AMyCppPawn::AMyCppPawn()
{

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlapColision = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapColision"));
	OverlapColision->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefualtSceneComponent"));
	DefaultSceneRoot->SetupAttachment(RootComponent);
	
	jumpMultiplier = 100.0f;

}

// Called when the game starts or when spawned
void AMyCppPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCppPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCppPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCppPawn::Jump()
{
	AddActorWorldOffset(GetActorUpVector() * jumpMultiplier);
}

void AMyCppPawn::StopJumping()
{
	AddActorWorldOffset(GetActorUpVector() * -jumpMultiplier);
}

void AMyCppPawn::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (APawn* pawn = Cast<APawn>(OtherActor))
	{
		overlappingpawn = pawn;
	}
}



void AMyCppPawn::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (overlappingpawn == OtherActor)
	{
		overlappingpawn = nullptr;
	}
	Super::NotifyActorEndOverlap(OtherActor);

}

