// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BiTreeNode.h"
#include "CoreMinimal.h"
#include "Interactable.h"
#include "PrintInteractable.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTTEST_API APrintInteractable : public AInteractable
{
	GENERATED_BODY()

public:

	void DoInteract() override;
	
	UPROPERTY(EditAnywhere, Category = "Interact")
	 TEnumAsByte<PrintFunction> function{PrintFunction::NONE};

	std::string printResult;
};
