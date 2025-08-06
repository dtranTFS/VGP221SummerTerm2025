// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameWidget.h"

void UGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetHealthBar(1.0f);
	SetScoreText(UIScore);

	for (int i = 0; i < 4; i++) {
		UUserWidget* Widget = CreateWidget(this, ButtonWidgetPrefab);
		ButtonContainer->AddChildToVerticalBox(Widget);

		UButtonWidget* Button = Cast<UButtonWidget>(Widget);
		Button->SetText(i);
	}
}

void UGameWidget::SetHealthBar(float percentage)
{
	if (!HealthBar) return;

	HealthBar->SetPercent(percentage);
}

void UGameWidget::SetScoreText(int amount)
{
	if (!ScoreText) return;

	UIScore += amount;
	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}
