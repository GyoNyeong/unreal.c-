// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMyCppPawn.h"
#include "MyPawn.h"
#include "MyActor.h"
#include "MyPlayerController.h"

void AMyMyCppPawn::BeginPlay()
{
	Super::BeginPlay();

}

void AMyMyCppPawn::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
}

void AMyMyCppPawn::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (AMyActor* myActor = Cast<AMyActor>(OtherActor))
	{
		AddGameScore();
		UE_LOG(LogTemp, Display, TEXT("OverlapEvent"));
	}

	Super::NotifyActorBeginOverlap(OtherActor);
}




void AMyMyCppPawn::AddGameScore_Implementation()
{
	gamescore++;
	UE_LOG(LogTemp, Display, TEXT("%i"), gamescore);
}

