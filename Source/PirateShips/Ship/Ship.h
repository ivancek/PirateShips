// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"


class UStaticMeshComponent;

UCLASS()
class PIRATESHIPS_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

protected:
	
	/* FUNCTIONS */

	virtual void BeginPlay() override;
	void ApplyForwardForce(float InputValue);
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetMeshComp(UStaticMeshComponent* InMeshComp);

	/* MEMBERS */

	/* The amount of power to move the ship */
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float Power;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
private:
	UStaticMeshComponent* MeshComp;
	
};
