// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"


UHeroAnimInstance::UHeroAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> MT(TEXT("AnimMontage'/Game/Animation/HeroAnimMontage.HeroAnimMontage'"));
	if (MT.Succeeded()) 
	{
		AttackMontage = MT.Object;
	}
}


void UHeroAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	

	Super::NativeUpdateAnimation(DeltaSeconds);

	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn)) 
	{
		Speed = pawn->GetVelocity().Size();

		auto Character = Cast<ACharacter>(pawn);
		if (Character) 
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();
		}
	}

}

void UHeroAnimInstance::PlayAttackMontage()
{
	//UE_LOG(LogTemp, Warning, TEXT("AttackTried"));
	if (!Montage_IsPlaying(AttackMontage))
	{
		Montage_Play(AttackMontage);

	}
}
