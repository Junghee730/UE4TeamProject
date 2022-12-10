// Fill out your copyright notice in the Description page of Project Settings.


#include "IsInRangeBTDecorator.h"
#include "EnemyAIController.h"
#include "./UE4Project/UE4ProjectCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UIsInRangeBTDecorator::UIsInRangeBTDecorator()
{
	NodeName = TEXT("CanAttack");
}

bool UIsInRangeBTDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return false;

	auto Target = Cast<AUE4ProjectCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey));
	if (nullptr == Target)
		return false;

	bResult = (Target->GetDistanceTo(ControllingPawn) <= 200.0f);
	return bResult;
}