// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HeroStatComponent.generated.h"


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

	int32 GetLevel() { return Level; }

	int32 GetHP() { return HP; }

	int32 GetAttackDamage() { return AttackDamage; }

private:
	UPROPERTY(EditAnywhere, Category=Stats, Meta=(AllowPrivateAccess=true))
	int32 Level;
	
	UPROPERTY(EditAnywhere, Category = Stats, Meta = (AllowPrivateAccess = true))
	int32 HP;

	UPROPERTY(EditAnywhere, Category = Stats, Meta = (AllowPrivateAccess = true))
	int32 AttackDamage;
		
};
