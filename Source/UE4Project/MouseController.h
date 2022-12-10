// Fill out your copyright notice in the Description page of Project Settings.
//박연지
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "MouseController.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API AMouseController : public APlayerController
{
	GENERATED_BODY()

public:
	AMouseController();

	UPROPERTY()
	FVector mouseLocation;

	UPROPERTY(BlueprintReadWrite)
	bool mouseClick;

	UFUNCTION(BlueprintCallable)
	void MouseMove();

	UFUNCTION()
	void MouseCursor(); //마우스 위치 가져옴

	UFUNCTION()
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void InputMouseLeft(float AxisValue);
};
