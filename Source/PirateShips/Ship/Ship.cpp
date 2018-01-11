// Fill out your copyright notice in the Description page of Project Settings.

#include "Ship.h"

#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShip::ApplyForwardForce(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	FVector FinalForce = ForwardDirection * Power;

	if (MeshComp)
	{
		MeshComp->AddForce(FinalForce);
	}
}

void AShip::SetMeshComp(UStaticMeshComponent * InMeshComp)
{
	MeshComp = InMeshComp;
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Forward", this, &AShip::ApplyForwardForce);
}

