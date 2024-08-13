// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCppPawn.h"
#include "MyInterface.h"
#include "MyMyCppPawn.generated.h"

/**
 * 
 */
UCLASS()
class CPP_PROJECT_API AMyMyCppPawn : public AMyCppPawn, public IMyInterface
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float Deltatime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	UFUNCTION()
	void AddGameScore_Implementation() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int gamescore;

	virtual void PossessedBy(AController* NewController) override;

	virtual void UnPossessed() override;
};
