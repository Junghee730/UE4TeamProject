// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectNpcBTService.h"
#include "EnemyAIController.h"
#include "./UE4Project/UE4ProjectCharacter.h"
#include "NpcSample.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UDetectNpcBTService::UDetectNpcBTService()
{
	NodeName = TEXT("DetectNPC");
	detectdRadius = 600.0f;
	Interval = 1.0f;
}

void UDetectNpcBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return;

	UWorld* World = ControllingPawn->GetWorld();
	FVector Center = ControllingPawn->GetActorLocation();

	if (nullptr == World) return;
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(detectdRadius),
		CollisionQueryParam
	);

	if (bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			ANpcSample* ABCharacter = Cast<ANpcSample>(OverlapResult.GetActor());
			if (ABCharacter)
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetNpcKey, ABCharacter);
				DrawDebugSphere(World, Center, detectdRadius, 16, FColor::Green, false, 0.2f);

				DrawDebugPoint(World, ABCharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), ABCharacter->GetActorLocation(), FColor::Blue, false, 0.27f);
				return;
			}
		}
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetNpcKey, nullptr);
	DrawDebugSphere(World, Center, detectdRadius, 16, FColor::Red, false, 0.2f);
}