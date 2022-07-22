// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroStatComponent.h"
#include "TrainingGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHeroStatComponent::UHeroStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	bWantsInitializeComponent = true;

	Level = 1;
}


// Called when the game starts
void UHeroStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UHeroStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetLevel(Level);
}

void UHeroStatComponent::SetLevel(int32 NewLevel)
{
	auto TrainingGameInstance = Cast<UTrainingGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (TrainingGameInstance) 
	{
		auto StatData = TrainingGameInstance->GetStatData(NewLevel);
		if (StatData) 
		{
			Level = StatData->Level;
			SetHP(StatData->MaxHP);
			MaxHP = StatData->MaxHP;
			AttackDamage = StatData->AttackDamage;
		}
	}
}

void UHeroStatComponent::SetHP(int NewHP) 
{
	HP = NewHP;
	if (HP < 0) HP = 0;

	OnHPChanged.Broadcast();
}


void UHeroStatComponent::OnAttacked(float DamageAmount)
{
	int32 NewHP = HP - DamageAmount;

	SetHP(NewHP);
	//UE_LOG(LogTemp, Warning, TEXT("Attacked! Remaining HP: %d"), HP);
}

