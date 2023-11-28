// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnForwardMovement.h"

// Sets default values for this component's properties
UPawnForwardMovement::UPawnForwardMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPawnForwardMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPawnForwardMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPawnForwardMovement::DetectAllCellsToMove(bool isWhite) {
	FVector DetectedLocation;
	TArray<AActor*> OverlappedActors; //actually i guess APawn should be put here
	TArray<FVector> PossibleMoves; //possible positions



	/*if (isWhite) {
		if (!HasEverMoved) {
			DetectingMovingLocation(DetectedLocation, 200.0f);
			//spawning collision box at Detected Location
			if (/*CB is not overlapped with smth) PossibleMoves.Add(DetectedLocation);
		}
		else {
			DetectingMovingLocation(DetectedLocation, 100.0f);
			//spawning collision box at Detected Location
			if (/*CB is not overlapped with smth) PossibleMoves.Add(DetectedLocation);
		}
		DetectingAttackingLocation(DetectedLocation, 100.0f, 100.0f);
		//spawning collision box at Detected Location
		if (/*CB is overlapped with smth) {
			PossibleMoves.Add(DetectedLocation);
			//adding overlapped actor to OverlappedActors
		}
		DetectingAttackingLocation(DetectedLocation, 100.0f, -100.0f);
		//spawning collision box at Detected Location
		if (/*CB is overlapped with smt) {
			PossibleMoves.Add(DetectedLocation);
			//adding overlapped actor to OverlappedActors
		}
	}
	else
	{
		if (!HasEverMoved) {
			DetectingMovingLocation(DetectedLocation, -200.0f);
			//spawning collision box at Detected Location
			if (/*CB is not overlapped with smth) PossibleMoves.Add(DetectedLocation);
		}
		else {
			DetectingMovingLocation(DetectedLocation, -100.0f);
			//spawning collision box at Detected Location
			if (/*CB is not overlapped with smth) PossibleMoves.Add(DetectedLocation);
		}
		DetectingAttackingLocation(DetectedLocation, -100.0f, 100.0f);
		//spawning collision box at Detected Location
		if (/*CB is overlapped with smth) {
			PossibleMoves.Add(DetectedLocation);
			//adding overlapped actor to OverlappedActors
		}
		DetectingAttackingLocation(DetectedLocation, -100.0f, -100.0f);
		//spawning collision box at Detected Location
		if (/*CB is overlapped with smth) {
			PossibleMoves.Add(DetectedLocation);
			//adding overlapped actor to OverlappedActors
		}
	}*/
}

//i need to restructure code into smaller funcs asa I found out what to place inseatd of green lines and fieelds

void UPawnForwardMovement::DetectingMovingLocation(FVector& DetectedLocation, float MovingValue)
{
	DetectedLocation = FVector(pawnFigure->GetActorLocation().X, pawnFigure->GetActorLocation().Y + MovingValue, 0.0f);
}

void UPawnForwardMovement::DetectingAttackingLocation(FVector& DetectedLocation, float MovingValue, float MovingValueSide) {
	DetectedLocation = FVector(pawnFigure->GetActorLocation().X + MovingValueSide , pawnFigure->GetActorLocation().Y + MovingValue, 0.0f);
}

void UPawnForwardMovement::ChooseCell() {
	//highlight cell
	//send to SetPosition
}