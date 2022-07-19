// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "HeroCharacter.h"


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

		auto Character = Cast<AHeroCharacter>(pawn);
		if (Character) 
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();

			Vertical = Character->UpDownValue;
			Horizontal = Character->LeftRightValue;
		}
	}
}

FName UHeroAnimInstance::GetAttackMontage(int32 SectionIndex)
{
	return FName(*FString::Printf(TEXT("Attack%d"), SectionIndex));
}

void UHeroAnimInstance::AnimNotify_AttackHit()
{
	//UE_LOG(LogTemp, Warning, TEXT("Hit!"));
	OnAttackHit.Broadcast();
}

void UHeroAnimInstance::PlayAttackMontage()
{
	//UE_LOG(LogTemp, Warning, TEXT("AttackTried"));
	Montage_Play(AttackMontage);
}

void UHeroAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontage(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}
