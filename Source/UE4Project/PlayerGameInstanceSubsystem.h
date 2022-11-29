// Fill out your copyright notice in the Description page of Project Settings.
//�ڿ���
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UPlayerGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	//�÷��̾� HP �� �÷��̾� ���ݷ��� ������ ���������� ���� �Ǳ� ������ ���� �ν��Ͻ��� ������
	UPROPERTY()
	int32 playerHP = 100;

	UPROPERTY()
	int32 playerPower = 100;
};
