// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FindPatrolTask.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UFindPatrolTask : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UFindPatrolTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
