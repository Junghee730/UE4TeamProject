// Fill out your copyright notice in the Description page of Project Settings.
//박연지
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerGameInstanceSubsystem.h"
//#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class UE4PROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()
	//플레이어 회전도 하게 해야함
public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Crash(int32 monsterPower); //부딪쳤을 때

private:
	UPROPERTY()
	UPlayerGameInstanceSubsystem* playerGISS;
};
