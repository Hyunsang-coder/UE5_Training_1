// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

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
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));


	//To position the mesh on the ground looking forward
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));


	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/ParagonYin/Characters/Heroes/Yin/Meshes/Yin.Yin'"));
	
	if (SM.Succeeded()) 
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHeroCharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &AHeroCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AHeroCharacter::Strafe);
	PlayerInputComponent->BindAxis("Yaw", this, &AHeroCharacter::Yaw);
}

void AHeroCharacter::Jump()
{
	UE_LOG(LogTemp, Warning, TEXT("Jump!"));
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