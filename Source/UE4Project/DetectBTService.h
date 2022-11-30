// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "DetectBTService.generated.h"

/*
 Detect BTService
 ���� ���� ������ Npc BTService�� ��ġ�ų� �θ� Ŭ���� ���� ��Ӱ��� �����
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