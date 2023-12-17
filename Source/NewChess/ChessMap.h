// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Figure.h"
#include "ChessMap.generated.h"

UCLASS()
class NEWCHESS_API AChessMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(Category = "Chess")
	AFigure* Grid[8][8] = {
		{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
		{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
		{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
		{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
		{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
		{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
		{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
		{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
	};

	//UPROPERTY(Category = "Chess")
	//	TArray<AFigure*> Grid;

	UFUNCTION(BlueprintCallable)
		void SetFigures(int x, int y, AFigure* figure);

	UFUNCTION(BlueprintCallable)
		void ClearCell(int x, int y);

	UFUNCTION(BlueprintCallable)
		AFigure* GetFigure(int x, int y);

	UFUNCTION(BlueprintCallable)
		FString ParseToGridCoordinate(int i);

	UFUNCTION(BlueprintCallable)
		FString ShowFiguresList(int x, int y);

	UFUNCTION(BlueprintCallable)
		bool isCellTaken(int x, int y);

	UFUNCTION(BlueprintCallable)
		void RealLocationToCells(FVector location, int& x, int& y);
};

