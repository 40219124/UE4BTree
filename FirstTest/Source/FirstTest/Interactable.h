// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"


UCLASS()
class FIRSTTEST_API AInteractable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractable();

	UFUNCTION(BlueprintImplementableEvent, Category = "Interact")
		void OnPlayerInteraction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void DoInteract();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
