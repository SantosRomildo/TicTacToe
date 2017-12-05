// Fill out your copyright notice in the Description page of Project Settings.

#include "TicTactoeWidget.h"
#include "TicTacToeActor.h"
#include "Engine/World.h"
#include "Gameframework/Actor.h"
#include "EngineUtils.h"


void UTicTactoeWidget::NativeConstruct()
{
	
	if (UButton* b1 = Cast<UButton>(GetWidgetFromName("Board1")))
	{
		b1->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board1);
	}
	if (UButton* b2 = Cast<UButton>(GetWidgetFromName("Board2")))
	{
		b2->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board2);
	}
	if (UButton* b3 = Cast<UButton>(GetWidgetFromName("Board3")))
	{
		b3->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board3);
	}
	if (UButton* b4 = Cast<UButton>(GetWidgetFromName("Board4")))
	{
		b4->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board4);
	}
	if (UButton* b5 = Cast<UButton>(GetWidgetFromName("Board5")))
	{
		b5->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board5);
	}
	if (UButton* b6 = Cast<UButton>(GetWidgetFromName("Board6")))
	{
		b6->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board6);
	}
	if (UButton* b7 = Cast<UButton>(GetWidgetFromName("Board7")))
	{
		b7->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board7);
	}
	if (UButton* b8 = Cast<UButton>(GetWidgetFromName("Board8")))
	{
		b8->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board8);
	}
	if (UButton* b9 = Cast<UButton>(GetWidgetFromName("Board9")))
	{
		b9->OnClicked.AddDynamic(this, &UTicTactoeWidget::Board9);
	}
			
	for (TActorIterator<ATicTacToeActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{		
		ticTacToe = *ActorItr;			
	}

}




void UTicTactoeWidget::Board1()
{
	if (ticTacToe->IsCellEmpty(0, 0)) {
		ticTacToe->GetPlayerChoice(0, 0);
		UpdateTextBoard();
	}
}

void UTicTactoeWidget::Board2()
{
	if (ticTacToe->IsCellEmpty(0, 1)) {
		ticTacToe->GetPlayerChoice(0, 1);
		UpdateTextBoard();
	}
}

void UTicTactoeWidget::Board3()
{
	if (ticTacToe->IsCellEmpty(0, 2)) {
		ticTacToe->GetPlayerChoice(0, 2);
		UpdateTextBoard();
	}
}

void UTicTactoeWidget::Board4()
{
	if (ticTacToe->IsCellEmpty(1, 0)) {
		ticTacToe->GetPlayerChoice(1, 0);
		UpdateTextBoard();
	}
}

void UTicTactoeWidget::Board5()
{
	if (ticTacToe->IsCellEmpty(1, 1)) {
		ticTacToe->GetPlayerChoice(1, 1);
		UpdateTextBoard();
	}
}

void UTicTactoeWidget::Board6()
{
	if (ticTacToe->IsCellEmpty(1, 2)) {
		ticTacToe->GetPlayerChoice(1, 2);
		UpdateTextBoard();
	}
}

void UTicTactoeWidget::Board7()
{
	if (ticTacToe->IsCellEmpty(2, 0)) {
		ticTacToe->GetPlayerChoice(2, 0);
		UpdateTextBoard();
	}	
}

void UTicTactoeWidget::Board8()
{
	if (ticTacToe->IsCellEmpty(2, 1)) {
		ticTacToe->GetPlayerChoice(2, 1);
		UpdateTextBoard();
	}
}

void UTicTactoeWidget::Board9()
{
	if (ticTacToe->IsCellEmpty(2, 2)) {
		ticTacToe->GetPlayerChoice(2, 2);	
		UpdateTextBoard();
	}
}

void UTicTactoeWidget::UpdateTextBoard()
{
	BoardText1 = FString(""+ticTacToe->ReturnCellValue(0, 0));
	BoardText2 = FString("" + ticTacToe->ReturnCellValue(0, 1));
	BoardText3 = FString("" + ticTacToe->ReturnCellValue(0, 2));
	BoardText4 = FString("" + ticTacToe->ReturnCellValue(1, 0));
	BoardText5 = FString("" + ticTacToe->ReturnCellValue(1, 1));
	BoardText6 = FString("" + ticTacToe->ReturnCellValue(1, 2));
	BoardText7 = FString("" + ticTacToe->ReturnCellValue(2, 0));
	BoardText8 = FString("" + ticTacToe->ReturnCellValue(2, 1));
	BoardText9 = FString("" + ticTacToe->ReturnCellValue(2, 2));

	

	if (ticTacToe->IsGameEnd()) {
		if (ticTacToe->GetWinnerName() == "d") {
			WinnerText = "Draw";
		}
		else if (ticTacToe->GetWinnerName() == "x") {
			WinnerText = "x Win";
		}
		else {
			WinnerText = "o Win";
		}
		PlayerTurn = "";
	}
	else {
		if (ticTacToe->IsPlayerTurn()) {
			PlayerTurn = "x Turn";
		}
		else {
			PlayerTurn = "o Turn";
		}
	}


}




