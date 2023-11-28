// Fill out your copyright notice in the Description page of Project Settings.


#include "LinesMovement.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
ULinesMovement::ULinesMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULinesMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULinesMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULinesMovement::DetectAllCellsToMove() {
	/*TArray<AActor*> OverlappedActors; //actually i guess APawn should be put here
	TArray<FVector> PossibleMoves; //possible positions
	FVector lineStart = GetComponentLocation();
	FVector lineEnd = lineStart + GetForwardVector() * maxGrabDistance; //it's for one direction, could be resturt to a method
	DrawDebugLine(GetWorld(), lineStart, lineEnd, FColor::Emerald);
	FHitResult HitResult;
	FCollisionShape CollisionSphere = FCollisionShape::MakeSphere(grabRadius);
	bool HasHit = CurrentWorld->SweepSingleByChannel(HitResult, //HitResult store the first object hit by the sweep
		lineStart, lineEnd,
		FQuat::Identity,
		//the nesessary collision channel, name could be found in DefaultEngine.ini,
		CollisionSphere);
	if (HasHit) {
		UE_LOG(LogTemp, Display, TEXT("Hit obj is %s"), *(HitResult.GetActor())->GetActorNameOrLabel());
	}
	else UE_LOG(LogTemp, Display, TEXT("Nothing to hit"));*/
}

void ULinesMovement::ChooseCell() {
	//highlight cell
	//send to SetPosition
}
