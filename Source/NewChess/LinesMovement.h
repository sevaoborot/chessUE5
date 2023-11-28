// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LinesMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWCHESS_API ULinesMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULinesMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	//void DetectingMovingLocation(FVector& DetectedLocation, float MovingValue);

	//void DetectingAttackingLocation(FVector& DetectedLocation, float MovingValueForward, float MovingValueSide);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void DetectAllCellsToMove(); //determines all possible places to move

	UFUNCTION()
		void ChooseCell(); //choose wished cell and send coordinates to the figure

private:
	UPROPERTY(VisibleAnywhere, Category = "ChessFigure")
		AActor* pawnFigure = GetOwner();

	UPROPERTY(EditAnywhere, Category = "ChessFigure")
		float maxGrabDistance = 400;

	UPROPERTY(EditAnywhere, Category = "ChessFigure")
		float grabRadius = 100;
};
