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


private: 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Pawn, Meta = (AllowPrivateAccess = true))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

public:
	void PlayAttackMontage();

};
