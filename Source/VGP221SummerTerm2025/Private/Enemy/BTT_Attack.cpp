// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTT_Attack.h"

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	float DamageAmt = OwnerComp.GetBlackboardComponent()->GetValueAsFloat(FName("DamageAmt"));
	DamageAmt = Cast<AEnemyAIController>(OwnerComp.GetAIOwner())->DamageAmt;
	DamageAmt = Cast<AEnemyAICharacter>(OwnerComp.GetAIOwner()->GetPawn())->CharacterDamageAmt;

	// Method 1: Using Gameplay static and calling a function
	// AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// player->Damage(DamageAmt);

	// Method 2: Using Blackboard Value
	// AFPSCharacter* player = Cast<AFPSCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("PlayerTarget")));
	// player->Damage(DamageAmt);

	// Method 3: Built in damage system
	AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UGameplayStatics::ApplyDamage(player, DamageAmt, OwnerComp.GetAIOwner(), OwnerComp.GetAIOwner()->GetPawn(), UDamageType::StaticClass());

	return EBTNodeResult::Succeeded;
}
