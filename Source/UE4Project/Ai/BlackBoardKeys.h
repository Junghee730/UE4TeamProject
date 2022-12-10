// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UE4PROJECT_API BlackBoardKeys
{
public:
	BlackBoardKeys();
	~BlackBoardKeys();
};


namespace BB_Keys
{
	TCHAR const* const targetLocation = TEXT("TargetLocation");
	TCHAR const* const canSeePlayer = TEXT("CanSeePlayer");
	TCHAR const* const playerIsInMeeleRange = TEXT("PlayerIsInMeeleRange");
}