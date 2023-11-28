// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnForwardMovement.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWCHESS_API UPawnForwardMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPawnForwardMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private: 
	void DetectingMovingLocation(FVector& DetectedLocation, float MovingValue);

	void DetectingAttackingLocation(FVector& DetectedLocation, float MovingValueForward, float MovingValueSide);

public:	
	//funcs

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void DetectAllCellsToMove(bool isWhite); //determines all possible places to move

	//UFUNCTION()
		//void CheckDetectedCells(); //checks if this cell is possible to move

	UFUNCTION()
		void ChooseCell(); //choose wished cell and send coordinates to the figure

	//properties

	UPROPERTY(EditAnywhere, Category = "ChessFigure") //Necessary for kings and pawns
		bool HasEverMoved = false;

private:
	UPROPERTY(VisibleAnywhere, Category = "ChessFigure")
		AActor* pawnFigure = GetOwner();

};
