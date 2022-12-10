// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	absBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	StaticMeshMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	SetRootComponent(StaticMeshMesh);
	absBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	absBox->SetupAttachment(StaticMeshMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ghostMaterialAsset(*ghostMaterialName);
	_ghostMaterial = ghostMaterialAsset.Object;

	if (mesh.Succeeded())
	{
		absBox->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
		StaticMeshMesh->SetStaticMesh(mesh.Object);
		StaticMeshMesh->SetMaterial(0, _ghostMaterial);
	}
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	const UEnum* EnemyStateEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EState"), true);
	if (EnemyStateEnum)
	{
		EnemyStateName = EnemyStateEnum->GetNameStringByValue((int64)EnemyState);
	}
	EnemyMaxHp = EnemyHp;
	EnemydieCheck = false;
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Attack ] : %d"), EnemyHp));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Max ] : %d"), EnemyMaxHp));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "State : " + EnemyStateName);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("===[Enemy]===")));

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void AEnemy::SetSubDamage_Implementation(int fightDamage)
{
	if (EnemyHp < fightDamage)
	{
		EnemyHp = EnemyHp - fightDamage;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ EnDamage_sub ] : %d"), EnemyHp));
		if (EnemyHp <= 0)
		{
			EnemyHp = 0;
			EnemydieCheck = true;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ enemydie ] : %d"), EnemydieCheck));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curEnDamage_sub ] : %d"), EnemyHp));
			EnemyDie();
		}
	}
	else
	{
		if (EnemyHp < fightDamage)
		{
			EnemyHp = fightDamage - EnemyHp;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curEnDamage_sub ] : %d"), EnemyHp));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ sibal ]")));
			if (EnemyHp <= 0)
			{
				EnemyHp = 0;
				EnemydieCheck = true;
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ enemydie ] : %d"), EnemydieCheck));
				EnemyDie();
			}
		}
		else
		{
			//EnemyHp = EnemyHp - fightDamage;
			//if (EnemyHp <= 0)
			/*{
				EnemyHp = 0;
				EnemydieCheck = true;
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ enemydie ] : %d"), EnemydieCheck));
				EnemyDie();
			}*/
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curEnDamage_sub ] : %d"), EnemyHp));
		}
	}


}

void AEnemy::EnemyDie()
{
	if (EnemyHp <= 0)
	{
		EnemyState = EState::Absorption;
		const UEnum* EnemyStateEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EState"), true);
		if (EnemyStateEnum)
		{
			EnemyStateName = EnemyStateEnum->GetNameStringByValue((int64)EnemyState);
		}
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "State : " + EnemyStateName);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Absorption ] ")));


	}


}

