// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "Components/BoxComponent.h"
#include "HeroCharacter.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PickUpWeapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PICKUPWEAPON"));
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> WM(TEXT("StaticMesh'/Game/ParagonShinbi/FX/Meshes/Hero_Specific/SM_Shinbi_Sword_Surround.SM_Shinbi_Sword_Surround'"));
	
	if (WM.Succeeded())
	{
		PickUpWeapon->SetStaticMesh(WM.Object);
	}
	PickUpWeapon->SetupAttachment(RootComponent);
	Trigger->SetupAttachment(PickUpWeapon);  

	PickUpWeapon->SetCollisionProfileName(TEXT("PickUp"));
	Trigger->SetCollisionProfileName(TEXT("PickUp"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
}

void APickUp::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &APickUp::OnCharacterOverlap);
}


void APickUp::OnCharacterOverlap(class UPrimitiveComponent* OverlappedComp,
	class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Event!"));

	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(OtherActor);
	if (HeroCharacter)
	{
		FName WeaponSocket(TEXT("rSocket"));

		AttachToComponent(HeroCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
	}
}
