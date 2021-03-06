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

	virtual void PostInitializeComponents() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:
	void MoveForward(float Value);
	void Strafe(float Value);
	void Yaw(float Value);
	void Pitch(float Value);
	void Attack();
	void AttackCheck();

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override
	{
		Super::SetupPlayerInputComponent(PlayerInputComponent);

		//Jump는 내장함수
		
		PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AHeroCharacter::Attack);
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHeroCharacter::Jump);
		PlayerInputComponent->BindAxis("MoveForward", this, &AHeroCharacter::MoveForward);
		PlayerInputComponent->BindAxis("Strafe", this, &AHeroCharacter::Strafe);
		PlayerInputComponent->BindAxis("Yaw", this, &AHeroCharacter::Yaw);

		// 카메라 위아래 움직임 추가 +BP에서 UsePawnControl Rotation + InheritPitch 체크! 
		PlayerInputComponent->BindAxis("LookUp", this, &AHeroCharacter::AddControllerPitchInput);
	}


private:

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

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
	class UHeroStatComponent* Stat;

	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* HPBar;


};
