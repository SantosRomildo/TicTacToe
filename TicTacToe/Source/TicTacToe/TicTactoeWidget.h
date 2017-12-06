// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "Components/Button.h"
#include "TicTactoeWidget.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UTicTactoeWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Turn")
	FString PlayerTurn = "x Turn";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Winner")
	FString WinnerText = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText1 = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText2 = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText3 = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText4 = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText5 = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText6 = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText7 = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText8 = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardText")
		FString BoardText9 = "";


	
	UPROPERTY()
	class ATicTacToeActor *ticTacToe;

private:
	UFUNCTION()
	void Board1();
	UFUNCTION()
	void Board2();
	UFUNCTION()
	void Board3();
	UFUNCTION()
	void Board4();
	UFUNCTION()
	void Board5();
	UFUNCTION()
	void Board6();
	UFUNCTION()
	void Board7();
	UFUNCTION()
	void Board8();
	UFUNCTION()
	void Board9();

	void UpdateTextBoard();
};
