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
private:
	bool isCpuGame;
	bool isGameFinished;
	bool waitForTurn;
	bool isPlayerTurn;
	char hashBoard[3][3];
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	
	bool GetIsCpuGame();
	bool IsWaitingForTurn();
	void GetPlayerChoice(int32 choiceX, int32 choiceY);
	bool IsCellEmpty(int32 choiceX, int32 choiceY);

	
	
};
