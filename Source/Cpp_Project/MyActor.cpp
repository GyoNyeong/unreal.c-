// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	StaticMeshCom = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{

	Super::BeginPlay();
	GetActorLocation();
	Position = GetActorLocation();
	
	Max = Position.X + 1000;
	Min = Position.X - 1000;
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // 위치 가져오기-한번만, x 이동 1000까지 -> 반대로 이동 - 1000까지 반복
	
	if (Switch==false)
	{
			Position.X+=10;
			SetActorLocation(FVector(Position.X, Position.Y, Position.Z));
		
		 if (Position.X == Max)
		{
			Switch = true;
		}
	}

	else
	{
		Position.X += -10;
		SetActorLocation(FVector(Position.X, Position.Y, Position.Z));
		
		if (Position.X == Min)
		{
			Switch = false;
		}

	}

	

}

