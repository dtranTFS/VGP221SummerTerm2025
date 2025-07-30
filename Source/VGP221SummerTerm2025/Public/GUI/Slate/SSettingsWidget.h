// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/GameHUD.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class VGP221SUMMERTERM2025_API SSettingsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingsWidget)
	{}
	SLATE_ARGUMENT(int, MyInt);
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwningHUD);
	SLATE_END_ARGS()

	int MyInt;
	TWeakObjectPtr<class AGameHUD> OwningHUD;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnResumeClicked() const;
	FReply OnSettingsClicked() const;
	FReply OnQuitClicked() const;
};

/*
	Smart Pointers

	TUniquePtr - Sole Ownership
		- Resource management small stuff

	SoftObjectPtr - Lazy loading
		- Assets that you may not want loaded yet in memory
		- TSoftObjectPtr<Texture> Crosshair;
			- Crosshair.LoadSynchonourly();

	SharedPtr/SharedRef - Shared ownership
		- Want multiple objects to be responsible for this memory

	WeakPtr - No ownership
		- Temporary access to memory
*/