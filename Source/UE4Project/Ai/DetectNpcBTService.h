// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "DetectNpcBTService.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UDetectNpcBTService : public UBTService
{
	GENERATED_BODY()
public:
	UDetectNpcBTService();

	UPROPERTY(EditAnywhere)
		float detectdRadius;

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
