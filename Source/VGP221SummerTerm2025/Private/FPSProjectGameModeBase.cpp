// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectGameModeBase.h"

void AFPSProjectGameModeBase::StartPlay()
{
    Super::StartPlay();

    check(GEngine != nullptr);

    // 1. To print to screen
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameModeBase!"));

    // 2. To print to console
    UE_LOG(LogTemp, Warning, TEXT("Hello World, this is FPSGameModeBase!"));

    // 3. Printing Values to console
    int TestNumber = 10;
    bool BoolTest = false;
    FString NameTest("Your string here");
    UE_LOG(LogTemp, Warning, TEXT("TestNumber: %i, BoolTest: %d, NameTest: %s"), TestNumber, BoolTest, *NameTest);

    int* NumPoint = &TestNumber;
    // Will output a random number associated with memory address
    UE_LOG(LogTemp, Warning, TEXT("NumPoint: %i"), NumPoint);
    // Dereference to display the actual number
    UE_LOG(LogTemp, Warning, TEXT("NumPoint: %i"), *NumPoint);

    // 4. Modern way of debugging values
    UE_LOGFMT(LogTemp, Warning, "TestNumber: {0}, BoolTest: {1}, NameTest {2}", TestNumber, BoolTest, "Name Test");
}