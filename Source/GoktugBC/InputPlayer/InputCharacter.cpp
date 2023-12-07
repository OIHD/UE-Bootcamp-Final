// Fill out your copyright notice in the Description page of Project Settings.


#include "GoktugBC/InputPlayer/InputCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "InputCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AInputCharacter::AInputCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm -> SetupAttachment(RootComponent) ;
	SpringArm -> bUsePawnControlRotation = true ;
	//Kamera 
	Kamera = CreateDefaultSubobject<UCameraComponent>("Kamera");
	Kamera->SetupAttachment(SpringArm);
	Kamera->bUsePawnControlRotation = true ;
	//
	bUseControllerRotationYaw = false ;
	GetCharacterMovement()->bOrientRotationToMovement =false ;
}

// Called when the game starts or when spawned
void AInputCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInputCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInputCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Input Mapping Contentleri burada 
	if (APlayerController* OyuncuKontrolcusu = Cast<APlayerController>(Controller))
	{
		//Get local player subsystem
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(OyuncuKontrolcusu->GetLocalPlayer() ))
		{
			//Add Input context
			subsystem->AddMappingContext(InputHaritasi, 0);
		}
	}

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(EtkilesimAction, ETriggerEvent::Triggered, this, &AInputCharacter::Etkilesim);
		Input->BindAction(HareketAction,ETriggerEvent::Triggered,this,&AInputCharacter::Hareket);
		Input->BindAction(SeyirAction,ETriggerEvent::Triggered,this,&AInputCharacter::Seyir);
		Input->BindAction(ZiplaAction,ETriggerEvent::Triggered,this,&AInputCharacter::Zipla);
	}



}

void AInputCharacter::Hareket(const FInputActionValue &InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	if (IsValid(Controller))
	{
		//Get Forward Direction 
		const FRotator Rotation = Controller ->GetControlRotation();
		const FRotator YawRotation(0,Rotation.Yaw,0);
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		//Add Movement
		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection , InputVector.X);

	}
	
}

void AInputCharacter::Seyir(const FInputActionValue &InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	if (IsValid(Controller))
	{
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
	
}

void AInputCharacter::Zipla()
{
	ACharacter::Jump();
}

void AInputCharacter::Etkilesim()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Magenta, "https://github.com/OIHD/unreal-bootcamp");
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Techcareer Unreal-Engine bootcamp");
}



