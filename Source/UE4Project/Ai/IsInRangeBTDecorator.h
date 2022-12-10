// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "IsInRangeBTDecorator.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UIsInRangeBTDecorator : public UBTDecorator
{
	GENERATED_BODY()
public:
	UIsInRangeBTDecorator();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
