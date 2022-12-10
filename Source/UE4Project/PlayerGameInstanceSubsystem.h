// Fill out your copyright notice in the Description page of Project Settings.
//박연지
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
	
	//플레이어 HP 및 플레이어 공격력은 게임이 끝날때까지 유지 되기 때문에 게임 인스턴스로 관리함
public:
	UPlayerGameInstanceSubsystem();

	UPROPERTY(BlueprintReadOnly)
	int32 playerPower;
};
