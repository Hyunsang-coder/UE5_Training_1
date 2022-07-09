// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroAnimInstance.h"

void UHeroAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn)) 
	{
		Speed = pawn->GetVelocity().Size();
	}

}
