
#include "TicTacToeActor.h"


ATicTacToeActor::ATicTacToeActor()
{
	PrimaryActorTick.bCanEverTick = true;
	isPlayerTurn = true;
	for (int32 i = 0; i < 3; i++) {
		for (int32 j = 0; j < 3; j++) {
			hashBoard[i][j] = '_';
		}
	}
	//retirar
	isCpuGame = false;
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
	if (!waitForTurn) {
		waitForTurn = true;
		if (!GetIsCpuGame()) {
			if (isPlayerTurn) {
				hashBoard[choiceX][choiceY] = 'x';
				isPlayerTurn = false;
			}
			else {
				hashBoard[choiceX][choiceY] = 'o';
				isPlayerTurn = true;
			}
		}
		else {

		}
	}
	waitForTurn = false;
}

bool ATicTacToeActor::IsCellEmpty(int32 choiceX, int32 choiceY) {
	if (!waitForTurn && hashBoard[choiceX][choiceY] == '_') {
		return true;
	}
	else {
		return false;
	}
	
}

