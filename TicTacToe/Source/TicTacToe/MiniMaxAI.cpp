// Fill out your copyright notice in the Description page of Project Settings.

#include "MiniMaxAI.h"

MiniMaxAI::MiniMaxAI()
{
}

MiniMaxAI::~MiniMaxAI()
{
}

bool MiniMaxAI::IsMovesLeft(FString board[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == empty) {
				return true;
			}
		}
	}
	return false;

}

int32 MiniMaxAI::CheckBoardValue(FString board[3][3])
{
	for (int row = 0; row < 3; row++) {
		if (board[row][0] == board[row][1] &&
			board[row][1] == board[row][2]) {
			if (board[row][0] == playerX) {
				return +10;
			}
			else if (board[row][0] == playerO) {
				return -10;
			}
		}
	}

	for (int col = 0; col < 3; col++) {
		if (board[0][col] == board[1][col] &&
			board[1][col] == board[2][col]) {
			if (board[0][col] == playerX) {
				return +10;
			}
			else if (board[0][col] == playerO) {
				return -10;
			}
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if (board[0][0] == playerX) {
			return +10;
		}
		else if (board[0][0] == playerO) {
			return -10;
		}
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if (board[0][2] == playerX) {
			return +10;
		}
		else if (board[0][2] == playerO) {
			return -10;
		}
	}

	return 0;

}

int32 MiniMaxAI::Minimax(FString board[3][3], int32 depth, bool isPlayer)
{
	int score = CheckBoardValue(board);


	if (score == 10) {
		return score;
	}

	if (score == -10) {
		return score;
	}

	if (IsMovesLeft(board) == false) {
		return 0;
	}


	if (isPlayer) {
		int best = -1000;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == empty) {
					board[i][j] = playerX;
					best = FMath::Max(best,
						Minimax(board, depth + 1, !isPlayer));
					board[i][j] = empty;
					if (depth <= 20) {
						break;
					}
				}
			}
		}
		return best;
	}
	else {
		int best = 1000;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == empty) {
					board[i][j] = playerO;
					best = FMath::Min(best,
						Minimax(board, depth + 1, !isPlayer));
					board[i][j] = empty;
					if (depth <= 20) {
						break;
					}
				}
			}
		}
		return best;
	}

	
}

void MiniMaxAI::FindNextMove(FString board[3][3], int32 &choiceX, int32 &choiceY)
{
	int bestVal = 1000;
	
	int32 row = -1;
	int32 col = -1;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == empty) {
				board[i][j] = playerO;
				int moveVal = Minimax(board, 0,true);
				board[i][j] = empty;
				if (moveVal < bestVal) {
					row = i;
					col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	choiceX = row;
	choiceY = col;	
}
