// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HeroAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5_TRAINING_1_API UHeroAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UHeroAnimInstance();


	virtual void NativeUpdateAnimation(float DeltaSecond) override;

	void PlayAttackMontage();
	void JumpToSection(int32 SectionIndex);
	
	FName GetAttackMontage(int32 SectionName);




private: 

	UFUNCTION()
	void AnimNotify_AttackHit();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Pawn, Meta = (AllowPrivateAccess = true))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	int32 Vertical;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	int32 Horizontal;

};
