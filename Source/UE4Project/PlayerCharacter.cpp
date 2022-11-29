// Fill out your copyright notice in the Description page of Project Settings.
//박연지

#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//playerGISS = UGameInstance::GetSubsystem<UPlayerGameInstanceSubsystem>(GetWorld()->GetGameInstance());
	playerGISS = GetGameInstance()->GetSubsystem<UPlayerGameInstanceSubsystem>(GetWorld()->GetGameInstance());

	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::Attack(int32 monsterPower) //일단 근거리 공격 기준으로 작업
{

}