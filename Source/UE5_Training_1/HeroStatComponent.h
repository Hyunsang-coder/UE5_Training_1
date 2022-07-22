// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HeroStatComponent.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnHPChanged)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5_TRAINING_1_API UHeroStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHeroStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

public:

	void SetLevel(int32 Level);
	void OnAttacked(float DamageAmount);
	void SetHP(int32 NewHP);


	int32 GetLevel() { return Level; }
	int32 GetHP() { return HP; }
	int32 GetMaxHP() { return MaxHP; }
	float GetHPRatio() { return HP / (float)MaxHP; }
	int32 GetAttackDamage() { return AttackDamage; }


private:
	
	UPROPERTY(VisibleAnywhere, Category=Stat, Meta=(AllowPrivateAccess))
		int32 Level;

	UPROPERTY(VisibleAnywhere, Category = Stat, Meta = (AllowPrivateAccess))
		int32 HP;

	UPROPERTY(VisibleAnywhere, Category = Stat, Meta = (AllowPrivateAccess))
		int32 MaxHP;

	UPROPERTY(VisibleAnywhere, Category = Stat, Meta = (AllowPrivateAccess))
		int32 AttackDamage;

public:
	FOnHPChanged OnHPChanged;
};