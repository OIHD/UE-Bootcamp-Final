// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
//------------------------------------
#include "InputCharacter.generated.h"

UCLASS()
class GOKTUGBC_API AInputCharacter : public ACharacter
{
	GENERATED_BODY()
	
	
	UPROPERTY(VisibleAnyWhere,meta = (AllowPrivateAcess = "true" ))
	class UCameraComponent* Kamera;

	UPROPERTY(VisibleAnyWhere,meta = (AllowPrivateAcess = "true" ))
	class USpringArmComponent* SpringArm ;

protected:

	UPROPERTY(EditAnyWhere, Category = "InputSistemi")
	class UInputMappingContext* InputHaritasi;

	UPROPERTY(EditAnyWhere, Category = "InputSistemi")
	class UInputAction* HareketAction ;

	UPROPERTY(EditAnyWhere, Category = "InputSistemi")
	class UInputAction* ZiplaAction ;

	UPROPERTY(EditAnyWhere, Category = "InputSistemi")
	class UInputAction* SeyirAction ;

	UPROPERTY(EditAnyWhere, Category = "InputSistemi")
	class UInputAction* EtkilesimAction;

	UPROPERTY(EditAnyWhere, Category = "InputSistemi")
	class UInputAction* GunAction;

public:
	// Sets default values for this character's properties
	AInputCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere)
	TSubclassOf<class AGunProjectile> GunProjectileActor;

	UFUNCTION(Server,Reliable)
	void GunServerShot();

protected:

	void Hareket(const FInputActionValue& InputValue);
	void Seyir(const FInputActionValue& InputValue);
	void Zipla();
	void Etkilesim() ;
	void Gun() ;

	


};
