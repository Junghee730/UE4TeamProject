// Fill out your copyright notice in the Description page of Project Settings.
//박연지

#include "MouseController.h"

AMouseController::AMouseController()
{
    bShowMouseCursor = true;
}

void AMouseController::MouseMove()
{
    APawn* const MyPawn = GetPawn();

    MouseCursor(); //마우스 위치 가져옴

    if (mouseClick == true)
    {
        UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, mouseLocation);
    }
    else if (mouseClick == false)
    {
        UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetActorLocation());
    }
}

void AMouseController::MouseCursor()
{
    FHitResult Hit;
    GetHitResultUnderCursor(ECC_Visibility, false, Hit);

    if (Hit.bBlockingHit)
    {
        mouseLocation = Hit.ImpactPoint;
    }
}

void AMouseController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAxis("MouseLeft", this, &AMouseController::InputMouseLeft);
}

void AMouseController::InputMouseLeft(float AxisValue)
{
    if (AxisValue > 0)
    {
        mouseClick = true;
    }
    else
    {
        mouseClick = false;
    }

    MouseMove();
}