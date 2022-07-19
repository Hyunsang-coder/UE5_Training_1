// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HeroCharacter.generated.h"

UCLASS()
class UE5_TRAINING_1_API AHeroCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHeroCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

<<<<<<< Updated upstream
=======
	virtual void PostInitializeComponents() override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:
>>>>>>> Stashed changes
	void MoveForward(float Value);
	void Strafe(float Value);
	void Yaw(float Value);
	void Pitch(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override
	{
		Super::SetupPlayerInputComponent(PlayerInputComponent);

		//Jump는 내장함수
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHeroCharacter::Jump);
		PlayerInputComponent->BindAxis("MoveForward", this, &AHeroCharacter::MoveForward);
		PlayerInputComponent->BindAxis("Strafe", this, &AHeroCharacter::Strafe);
		PlayerInputComponent->BindAxis("Yaw", this, &AHeroCharacter::Yaw);

		// 강의에 없었지만 카메라 위아래 움직임 추가 +BP에서 InheritPitch 체크! 
		PlayerInputComponent->BindAxis("LookUp", this, &AHeroCharacter::AddControllerPitchInput);
	}


private:

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

<<<<<<< Updated upstream
=======
	UPROPERTY(VisibleAnywhere, Category=Pawn)
	bool IsAttacking = false;

	UPROPERTY()
	class UHeroAnimInstance* AnimInstance;

	UPROPERTY()
	int32 AttackIndex = 0;


public:
	UPROPERTY()
	int32 UpDownValue = 0;

	UPROPERTY()
	int32 LeftRightValue = 0;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Weapon;

	UPROPERTY(VisibleAnywhere)
	class UHeroStatComponent* Stat;
>>>>>>> Stashed changes


};
