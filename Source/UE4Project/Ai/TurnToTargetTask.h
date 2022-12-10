// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TurnToTargetTask.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UTurnToTargetTask : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UTurnToTargetTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
