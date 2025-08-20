// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectibles/Coin.h"

ACoin::ACoin()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CoinMeshComponent) {
		CoinMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));

		static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(TEXT("/Game/Meshes/Projectile/Sphere.Sphere"));

		if (SphereMeshAsset.Succeeded()) {
			CoinMeshComponent->SetStaticMesh(SphereMeshAsset.Object);
			CoinMeshComponent->SetRelativeScale3D(FVector(0.6, 0.1, 0.6));
			CoinMeshComponent->SetupAttachment(CollisionComponent);
		}
	}
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
}

void ACoin::OnCollect()
{
	Super::OnCollect();

	UE_LOG(LogTemp, Warning, TEXT("Coin OnCollect Called"));

	RotationRate = OnCollectRotationRate;

	// C++ version of delay node
	GetWorldTimerManager().SetTimer(DeadTimerHandle, this, &ACoin::DeathTimerComplete, 0.5f, false);
}

void ACoin::DeathTimerComplete()
{
	AGameHUD* gameHUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AGameHUD>();
	gameHUD->GameWidgetContainer->SetScoreText(Points);

	Destroy();
}
