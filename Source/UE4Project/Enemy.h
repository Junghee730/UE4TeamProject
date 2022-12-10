// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerGameInstanceSubsystem.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/Components/BoxComponent.h"
#include "Enemy.generated.h"


UENUM(BlueprintType)
enum class EState : uint8
{
	Enemy,
	Absorption
};
UCLASS()
class UE4PROJECT_API AEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat", meta=(ClampMin = 0))
		int EnemyHp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		int EnemyMaxHp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		bool EnemydieCheck;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		EState EnemyState = EState::Enemy;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		FString EnemyStateName = FString(TEXT(""));

public:
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* StaticMeshMesh;
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* absBox;
	UPROPERTY(VisibleInstanceOnly)
		UMaterialInterface* _ghostMaterial = nullptr;
	UPROPERTY(VisibleAnywhere)
		FString ghostMaterialName = "Material'/Game/Material/EnemyColor_Inst'";

public:
	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "EnemyStat")
		void SetAddDamage(int fightDamage);*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "EnemyStat")
		void SetSubDamage(int fightDamage);
	UFUNCTION(BlueprintCallable, category = "EnemyDie")
		void EnemyDie();
};
