#include "InputDiceValAction.h"
#include "Grid.h"
#include "Player.h"

InputDiceValAction::InputDiceValAction(ApplicationManager* pApp) : Action (pApp)
{
}

void InputDiceValAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();	
	bool IsGameEnded = pGrid->GetEndGame();
	if (!IsGameEnded)
	{
		pOut->PrintMessage("Enter a dice Value between 1-6 .");
		int InputDiceValue;
		InputDiceValue = pIn->GetInteger(pOut);
		
		if (InputDiceValue > 0 && InputDiceValue < 7) 
		{
			DiceValue = InputDiceValue;
		}
		else
		{
			InputDiceValue = -1;
			int x, y;
			pOut->PrintMessage("The dice Value you entered is not bewtween 1-6 ,Click to continue...");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	pOut->ClearStatusBar();


}

void InputDiceValAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	bool IsGameEnded = pGrid->GetEndGame();
	if (!IsGameEnded && DiceValue != 0)
	{
		pOut->PrintMessage("The Dice Value you entered is " + to_string(DiceValue) + ", click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		Player* currentPlayer = pGrid->GetCurrentPlayer();
		currentPlayer->Move(pGrid, DiceValue);
		pOut->ClearStatusBar();
		pGrid->AdvanceCurrentPlayer();
	}

}

InputDiceValAction:: ~InputDiceValAction()
{

}