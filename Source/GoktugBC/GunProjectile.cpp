// Fill out your copyright notice in the Description page of Project Settings.


#include "GunProjectile.h"

// Sets default values
AGunProjectile::AGunProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	GunProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT ("Gun Projectile Mesh"));
	RootComponent = GunProjectileMesh;
 
	GunProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT ("Gun Projectile Component"));
	GunProjectileComponent-> InitialSpeed = 5000 ;
	GunProjectileComponent -> MaxSpeed = 10000 ;
}

// Called when the game starts or when spawned
void AGunProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

