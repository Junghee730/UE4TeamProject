// Fill out your copyright notice in the Description page of Project Settings.
//�ڿ���
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
	//�÷��̾� ȸ���� �ϰ� �ؾ���
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
	void Crash(int32 monsterPower); //�ε����� ��

private:
	UPROPERTY()
	UPlayerGameInstanceSubsystem* playerGISS;
};
