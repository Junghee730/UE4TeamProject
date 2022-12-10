// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

// https://koreanfoodie.me/895

const FName AEnemyAIController::HomePosKey(TEXT("HomePos"));
const FName AEnemyAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AEnemyAIController::TargetKey(TEXT("TargetPlayer"));
const FName AEnemyAIController::TargetNpcKey(TEXT("TargetNpc"));

AEnemyAIController::AEnemyAIController()
{
	//RepeatInterval = 3.0f;
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/EnemyAi/EnemyBB.EnemyBB"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/EnemyAi/EnemyBT.EnemyBT"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		if (!RunBehaviorTree(BTAsset))
		{

		}
	}
}