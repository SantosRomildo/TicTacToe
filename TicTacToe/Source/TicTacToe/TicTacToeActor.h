// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TicTacToeActor.generated.h"

UCLASS()
class TICTACTOE_API ATicTacToeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATicTacToeActor();
	int count;
	const FString playerX = "x";
	const FString playerO = "o";
	const FString empty = "_";
	const FString draw = "d";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)	
	bool isCpuGame;
private:
	bool isGameFinished;
	bool waitForTurn;
	bool isPlayerTurn;
	FString hashBoard[3][3];
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	
	bool GetIsCpuGame();
	bool IsPlayerTurn();
	bool IsWaitingForTurn();
	bool IsGameEnd();
	void GetPlayerChoice(int32 choiceX, int32 choiceY);
	bool IsCellEmpty(int32 choiceX, int32 choiceY);	
	FString ReturnCellValue(int32 choiceX, int32 choiceY);
	FString GetWinnerName();
	

	
	
};
