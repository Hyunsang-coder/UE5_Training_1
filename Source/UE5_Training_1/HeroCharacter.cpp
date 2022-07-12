// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "HeroAnimInstance.h"

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
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	AnimInstance = Cast<UHeroAnimInstance>(GetMesh()->GetAnimInstance());
	AnimInstance->OnMontageEnded.AddDynamic(this, &AHeroCharacter::OnAttackMontageEnded);
	
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
}

void AHeroCharacter::Strafe(float Value)
{
	//Get the forward direction of the actor then add the input value 
	AddMovementInput(GetActorRightVector(), Value);
}

void AHeroCharacter::Yaw(float Value)
{
	//Make sure to have the Yaw option is enabled on the Controller component 
	AddControllerYawInput(Value);
}

void AHeroCharacter::Attack()
{
	if (IsAttacking) return;

	AnimInstance->PlayAttackMontage();
	AnimInstance->JumpToSection(AttackIndex);

	AttackIndex = (AttackIndex + 1) % 3;

	IsAttacking = true;
}
