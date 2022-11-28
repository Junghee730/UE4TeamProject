// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseController.h"

AMouseController::AMouseController()
{
    bShowMouseCursor = true;
}

void AMouseController::MouseLeftPressed(const FVector& Location)
{
    MoveToMouseCursor();

    //ó���� �����ϸ� ����� ���ٰ� ���ߴ� ���� ����
    //�����Ҷ� ���콺 �Է��� 0�̿��� else if���� ���۵Ǵµ� �÷��̾��� ��ġ ���� 0, 0, 0�̿��� �׷� �� ����
    //�����Ҷ� �÷��̾��� ��ġ �� ���� �ʿ� or ������ ���콺 Ŭ�� ���̴� �̵��� �� ���� ���Ƴ���
    if (mouseClick == true)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("mouseClick == true"));
        playerLocation = Location;
        UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, mouseLocation);
    }
    else if (mouseClick == false)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("mouseClick == false"));
        UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, playerLocation);
    }

    //�̷��� �ϸ� ������ ���콺�� ���� �� �ʱ��� �� ����.
    //���콺�� ���� �ٷ� ���߰� �ؾ���
}

void AMouseController::MoveToMouseCursor()
{
    FHitResult Hit;
    GetHitResultUnderCursor(ECC_Visibility, false, Hit);

    if (Hit.bBlockingHit)
    {
        mouseLocation = Hit.ImpactPoint;
    }
}