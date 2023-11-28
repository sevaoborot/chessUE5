// Fill out your copyright notice in the Description page of Project Settings.


#include "Figure.h"
#include "ChessMap.h"

// Sets default values
AFigure::AFigure()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFigure::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFigure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFigure::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFigure::ChangeLocation(FVector NewLocation, AChessMap* ChessMap) 
{
	int currentX, currentY;
	countGridPos(currentX, currentY);
	ChessMap->SetFigures(currentX, currentY, NULL);
	SetActorLocation(NewLocation);
	countGridPos(currentX, currentY);
	ChessMap->SetFigures(currentX, currentY, this);
	//note: add chess cell ID to show the info on a display
}

void AFigure::DeleteFigure(AChessMap* ChessMap)
{
	int currentX, currentY;
	countGridPos(currentX, currentY);
	ChessMap->SetFigures(currentX, currentY, NULL);
	this->Destroy();
    //note: add chess cell ID to show the info on a display
}

void AFigure::countGridPos(int& x, int& y)
{
	FVector location = this->GetActorLocation();
	x = location.X / 100;
	y = location.Y / 100;
}
