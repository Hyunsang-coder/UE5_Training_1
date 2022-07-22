// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterWidget.h"
#include "HeroStatComponent.h"
#include "Components/ProgressBar.h"

void UCharacterWidget::BindHp(class UHeroStatComponent* StatComp)
{
	//PB_HPBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HPBar")));
	HeroStatComp = StatComp;
	HeroStatComp->OnHPChanged.AddUObject(this, &UCharacterWidget::UpdateHP);
}

void UCharacterWidget::UpdateHP()
{
	if (HeroStatComp.IsValid()) 
	{
		PB_HPBar->SetPercent(HeroStatComp->GetHPRatio());
	}

}
