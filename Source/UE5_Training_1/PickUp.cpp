// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PickUpWeapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PICKUPWEAPON"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> WM(TEXT(""));

	if (WM.Succeeded()) 
	{
		PickUpWeapon->SetStaticMesh(WM.Object);
	}
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}
