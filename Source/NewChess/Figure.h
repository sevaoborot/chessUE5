// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "ChessMap.h"
#include "Figure.generated.h"

class AChessMap; // https://unrealcommunity.wiki/forward-declarations-teqxgfp6 forward declaration

UCLASS()
class NEWCHESS_API AFigure : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFigure();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void ChangeLocation(FVector NewLocation, AChessMap* ChessMap); //Moves figure to its new location

	UFUNCTION(BlueprintCallable)
		void DeleteFigure(AChessMap* ChessMap); //Deletes eliminated figure figure

	UFUNCTION(BlueprintCallable)
		void countGridPos(int& x, int&y);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ChessFigure")
		bool IsWhite;

	UPROPERTY(EditAnywhere, Category = "ChessFigure") //movement dir
		FVector Direction;

	UPROPERTY(EditAnywhere, Category = "ChessFigure")
		int maxMovement;

	UFUNCTION(BlueprintCallable)
		FVector countRealPos(int& x, int& y);
};
