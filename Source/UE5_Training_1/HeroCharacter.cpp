// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "HeroAnimInstance.h"
#include "DrawDebugHelpers.h"
#include "PickUp.h"
<<<<<<< Updated upstream
=======
#include "HeroStatComponent.h"
>>>>>>> Stashed changes

// Sets default values
AHeroCharacter::AHeroCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 300.f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetRelativeLocation(FVector(30.f, 0.f, 60.f));
	SpringArm->SetRelativeRotation(FRotator(-10.f, 0.f, 0.f));


	//To position the mesh on the ground looking forward
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));


	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/ParagonSerath/Characters/Heroes/Serath/Meshes/Serath.Serath'"));
	
	if (SM.Succeeded()) 
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}
<<<<<<< Updated upstream
=======

	Stat = CreateDefaultSubobject<UHeroStatComponent> (TEXT("STAT"));
>>>>>>> Stashed changes
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	//FName WeaponSocket(TEXT("rSocket"));

	//auto PickUpWeapon = GetWorld()->SpawnActor<APickUp>(FVector::ZeroVector, FRotator::ZeroRotator);

	/*if (PickUpWeapon)
	{
		PickUpWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
	}*/
}

void AHeroCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AnimInstance = Cast<UHeroAnimInstance>(GetMesh()->GetAnimInstance());


	// Delegate´Â PostInitializeComponents¿¡¼­...
	if (AnimInstance) 
	{
		AnimInstance->OnMontageEnded.AddDynamic(this, &AHeroCharacter::OnAttackMontageEnded);
		AnimInstance->OnAttackHit.AddUObject(this, &AHeroCharacter::AttackCheck);
	}

}

// Called every frame
void AHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeroCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	IsAttacking = false;
}

void AHeroCharacter::MoveForward(float Value)
{
	//Get the forward direction of the actor then add the input value 
	AddMovementInput(GetActorForwardVector(), Value);

	UpDownValue = Value;
}

void AHeroCharacter::Strafe(float Value)
{
	//Get the forward direction of the actor then add the input value 
	AddMovementInput(GetActorRightVector(), Value);

	LeftRightValue = Value;
}

void AHeroCharacter::Yaw(float Value)
{
	//Make sure to have the Yaw option is enabled on the Controller component 
	AddControllerYawInput(Value);
}
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes

void AHeroCharacter::Attack()
{
	if (IsAttacking) return;

	AnimInstance->PlayAttackMontage();
	AnimInstance->JumpToSection(AttackIndex);

	AttackIndex = (AttackIndex + 1) % 3;

	IsAttacking = true;
}

void AHeroCharacter::AttackCheck()
{
	//UE_LOG(LogTemp, Warning, TEXT("Delegation called!"));

	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);

	float AttackRange = 100.f;
	float AttackRadius = 50.f;

	bool bResult = GetWorld()->SweepSingleByChannel(OUT HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_EngineTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius),
		Params);
	FVector Vec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + Vec * 0.5f;
	float HalfHeight = AttackRange*0.5f + AttackRadius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
	FColor DrawColor;
	
	if (bResult) 
	{
		DrawColor = FColor::Green;
	}
	else 
	{
		DrawColor = FColor::Red;
	}

	DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius, Rotation, DrawColor, false, 2.f);
<<<<<<< Updated upstream
}
=======

	if (bResult && HitResult.GetActor()) 
	{
		UE_LOG(LogTemp, Log, TEXT("Hit Actor : %s"), *HitResult.GetActor()->GetName());

		FDamageEvent DamageEvent;
		HitResult.GetActor()->TakeDamage(Stat->GetAttackDamage(), DamageEvent, GetController(), this);
	}
}
>>>>>>> Stashed changes
