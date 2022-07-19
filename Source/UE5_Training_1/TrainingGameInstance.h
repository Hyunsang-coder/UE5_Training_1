// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "TrainingGameInstance.generated.h"

/**
 * 
 */

USTRUCT()
struct FHeroCharacterData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AttackDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHP;
};

UCLASS()
class UE5_TRAINING_1_API UTrainingGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
};
