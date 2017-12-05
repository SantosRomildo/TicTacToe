// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TICTACTOE_API MiniMaxAI
{
public:
	MiniMaxAI();
	~MiniMaxAI();
	const FString playerX = "x";
	const FString playerO = "o";
	const FString empty = "_";
		
private:
	int32 CheckBoardValue(FString board[3][3]);
	int32 Minimax(FString board[3][3], int32 depth, bool IsPlayer);

public:
	bool IsMovesLeft(FString board[3][3]);
	void FindNextMove(FString board[3][3], int32 &choiceX, int32 &choiceY);
};
