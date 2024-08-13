// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMyCppPawn.h"
#include "MyPawn.h"
#include "MyActor.h"
#include "MyPlayerController.h"

void AMyMyCppPawn::BeginPlay()
{
	Super::BeginPlay();
	gamescore = 0;

}

void AMyMyCppPawn::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
}

void AMyMyCppPawn::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (AMyActor* myActor = Cast<AMyActor>(OtherActor))
	{
		//AddGameScore();
		//AMyMyCppPawn :: AddGameScore();
		//IMyInterface :: AddGameScore();
		Execute_AddGameScore(this);
		UE_LOG(LogTemp, Display, TEXT("%i"), gamescore);
	
	}

	Super::NotifyActorBeginOverlap(OtherActor);
}


void AMyMyCppPawn::AddGameScore_Implementation()
{
	gamescore++;
}



void AMyMyCppPawn::PossessedBy(AController* NewController)
{
	AMyPlayerController* myPlayerConteroller = Cast<AMyPlayerController>(NewController);
	if (myPlayerConteroller)
	{
		myPlayerConteroller->jumpdelegate.AddDynamic(this, &AMyMyCppPawn::Jump);
	
		myPlayerConteroller->Sjumpdelegate.AddDynamic(this, &AMyMyCppPawn::StopJumping);
		
	}
}


void AMyMyCppPawn::UnPossessed()
{
	AMyPlayerController* myPlayerConteroller = Cast<AMyPlayerController>(GetController());
	if (myPlayerConteroller)
	{
		myPlayerConteroller->jumpdelegate.Clear();
		myPlayerConteroller->Sjumpdelegate.Clear();
		
	}
}





