// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class UE5_TRAINING_1_API UCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindHp(class UHeroStatComponent* StatComp);

	void UpdateHP();

private:
	TWeakObjectPtr<class UHeroStatComponent> HeroStatComp;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_HPBar;
};
