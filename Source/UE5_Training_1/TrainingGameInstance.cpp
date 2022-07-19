// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingGameInstance.h"

UTrainingGameInstance::UTrainingGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("DataTable'/Game/Data/StatTable.StatTable'"));
	HeroStats = DATA.Object;
}

void UTrainingGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("MaxHP: %d"), GetSetData(1)->MaxHP);
}

FHeroCharacterData* UTrainingGameInstance::GetSetData(int32 Level)
{
	return HeroStats->FindRow<FHeroCharacterData>(*FString::FromInt(Level), TEXT(""));
}
