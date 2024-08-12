// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCppPawn.h"
#include "MyMyCppPawn.generated.h"

/**
 * 
 */
UCLASS()
class CPP_PROJECT_API AMyMyCppPawn : public AMyCppPawn
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float Deltatime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddGameScore();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int gamescore;

};
