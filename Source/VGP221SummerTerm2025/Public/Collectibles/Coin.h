// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectibles/Collectible.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/GameHUD.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SUMMERTERM2025_API ACoin : public ACollectible
{
	GENERATED_BODY()

public:
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* CoinMeshComponent;

	UPROPERTY(EditAnywhere)
	float Points = 1;
	UPROPERTY(EditAnywhere)
	float RotationRate = 100;
	UPROPERTY(EditAnywhere)
	float OnCollectRotationRate = 1500;

	FTimerHandle DeadTimerHandle;
	void DeathTimerComplete();
};
