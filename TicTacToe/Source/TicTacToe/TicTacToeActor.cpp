
#include "TicTacToeActor.h"
#include "MiniMaxAI.h"

ATicTacToeActor::ATicTacToeActor()
{
	PrimaryActorTick.bCanEverTick = true;
	isPlayerTurn = true;
	for (int32 i = 0; i < 3; i++) {
		for (int32 j = 0; j < 3; j++) {
			hashBoard[i][j] = empty;
		}
	}

}

void ATicTacToeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATicTacToeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATicTacToeActor::GetIsCpuGame() {	
	return isCpuGame;
}
bool ATicTacToeActor::IsWaitingForTurn() {
	return waitForTurn;
}



void ATicTacToeActor::GetPlayerChoice(int32 choiceX, int32 choiceY) {
	if (!waitForTurn && !IsGameEnd()) {
		waitForTurn = true;
		if (!GetIsCpuGame()) {
			if (isPlayerTurn) {
				hashBoard[choiceX][choiceY] = playerX;
				isPlayerTurn = false;
			}
			else {
				hashBoard[choiceX][choiceY] = playerO;
				isPlayerTurn = true;
			}
		}
		else {
			hashBoard[choiceX][choiceY] = playerX;
			MiniMaxAI miniMaxAi = MiniMaxAI();
			if (!IsGameEnd() && miniMaxAi.IsMovesLeft(hashBoard)) {
				int32 cpuChoiceX;
				int32 cpuChoiceY;
				miniMaxAi.FindNextMove(hashBoard, cpuChoiceX, cpuChoiceY);
				hashBoard[cpuChoiceX][cpuChoiceY] = playerO;
			}
		}
	}
	waitForTurn = false;
}

bool ATicTacToeActor::IsCellEmpty(int32 choiceX, int32 choiceY) {
	if (!waitForTurn && hashBoard[choiceX][choiceY] == empty) {
		return true;
	}
	else {
		return false;
	}
	
}


FString ATicTacToeActor::ReturnCellValue(int32 choiceX, int32 choiceY) {
	if ( !IsCellEmpty(choiceX,choiceY)) {
		return hashBoard[choiceX][choiceY];		
	}
	else {
		return "";
	}
}

bool ATicTacToeActor::IsPlayerTurn() {
	return isPlayerTurn;
}

FString ATicTacToeActor::GetWinnerName() {
	for (int row = 0; row < 3; row++) {
		if (hashBoard[row][0] == hashBoard[row][1] &&
			hashBoard[row][1] == hashBoard[row][2]) {
			if (hashBoard[row][0] == playerX) {
				return playerX;
			}
			else if (hashBoard[row][0] == playerO) {
				return playerO;
			}
		}
	}

	for (int col = 0; col < 3; col++) {
		if (hashBoard[0][col] == hashBoard[1][col] &&
			hashBoard[1][col] == hashBoard[2][col]) {
			if (hashBoard[0][col] == playerX) {
				return playerX;
			}
			else if (hashBoard[0][col] == playerO) {
				return playerO;
			}
		}
	}

	if (hashBoard[0][0] == hashBoard[1][1] && hashBoard[1][1] == hashBoard[2][2]) {
		if (hashBoard[0][0] == playerX) {
			return playerX;
		}
		else if (hashBoard[0][0] == playerO) {
			return playerO;
		}
	}

	if (hashBoard[0][2] == hashBoard[1][1] && hashBoard[1][1] == hashBoard[2][0]) {
		if (hashBoard[0][2] == playerX) {
			return playerX;
		}
		else if (hashBoard[0][2] == playerO) {
			return playerO;
		}
	}

	return draw;
}

bool ATicTacToeActor::IsGameEnd()
{
	for (int row = 0; row < 3; row++) {
		if (hashBoard[row][0] == hashBoard[row][1] &&
			hashBoard[row][1] == hashBoard[row][2]) {
			if (hashBoard[row][0] != empty)
				return true;
		}
	}
	for (int col = 0; col < 3; col++) {
		if (hashBoard[0][col] == hashBoard[1][col] &&
			hashBoard[1][col] == hashBoard[2][col]) {
			if (hashBoard[0][col] != empty)
				return true;
		}
	}
	if (hashBoard[0][0] == hashBoard[1][1] && hashBoard[1][1] == hashBoard[2][2]) {
		if (hashBoard[0][0] != empty)
			return true;
	}

	if (hashBoard[0][2] == hashBoard[1][1] && hashBoard[1][1] == hashBoard[2][0]) {
		if (hashBoard[0][2] != empty)
			return true;
	}
	return false;
}

bool ATicTacToeActor::IsMovesLeft()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (hashBoard[i][j] == empty) {
				return true;
			}
		}
	}
	return false;
}




