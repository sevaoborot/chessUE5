// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessMap.h"
#include <stdio.h>

// Sets default values
AChessMap::AChessMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Grid.Init(NULL, 64);//fill the grid with empty 64 values
}

// Called when the game starts or when spawned
void AChessMap::BeginPlay()
{
	//Super::BeginPlay();
}

// Called every frame
void AChessMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AChessMap::SetFigures(int x,int y, AFigure* figure) {
	if (Grid[x][y]!=NULL) Grid[x][y] = figure;
	UE_LOG(LogTemp, Display, TEXT("Dot: x %d and y %d"), x, y);
}

AFigure* AChessMap::GetFigure(int x, int y) {
	return Grid[x][y]; 
}

FString AChessMap::ParseToGridCoordinate(int i) {
	int x = i % 8;
	int y = i / 8;
	FString xy = FString::FromInt(x) + FString::FromInt(y);
	return xy;
}