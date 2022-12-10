// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "DetectBTService.generated.h"

/*
 Detect BTService
 추후 여유 있으면 Npc BTService와 합치거나 부모 클래로 만들어서 상속관계 만들기
 */
UCLASS()
class UE4PROJECT_API UDetectBTService : public UBTService
{
	GENERATED_BODY()
public:
	UDetectBTService();

	UPROPERTY(EditAnywhere)
		float detectdRadius;
		
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};