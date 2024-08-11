// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class CPP_PROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int Max;
	FVector Position;
	int Min;
	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* StaticMeshCom;
	bool Switch = false;



	void Increase()
	{
		if (Switch == false)
		{
			Position.X++;
		}
	}

	void Decrease()
	{
		if (Switch == true)
		{
			Position.X--;
		}
	}

};
