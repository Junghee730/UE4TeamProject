// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnToTargetTask.h"
#include "./UE4Project/UE4ProjectCharacter.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UTurnToTargetTask::UTurnToTargetTask()
{
	NodeName = TEXT("Turn");
}

EBTNodeResult::Type UTurnToTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ABCharacter = Cast<AUE4ProjectCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ABCharacter)
		return EBTNodeResult::Failed;

	auto Target = Cast<AUE4ProjectCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey));
	if (nullptr == Target)
		return EBTNodeResult::Failed;

	FVector LookVector = Target->GetActorLocation() - ABCharacter->GetActorLocation();
	LookVector.Z = 0.0f;
	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	ABCharacter->SetActorRotation(FMath::RInterpTo(ABCharacter->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 2.0f));

	return EBTNodeResult::Succeeded;
}