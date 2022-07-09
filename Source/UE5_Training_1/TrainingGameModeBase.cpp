// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingGameModeBase.h"
#include "HeroCharacter.h"



ATrainingGameModeBase::ATrainingGameModeBase() 
{

	//DefaultPawnClass = AHeroCharacter::StaticClass();

	// Note that _C is added to the end of the path!
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/BluePrints/BP_HeroCharacter.BP_HeroCharacter_C'"));

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}
	else 
	{
		UE_LOG(LogTemp, Log, TEXT("BP CLASS Failed"));
	}
}