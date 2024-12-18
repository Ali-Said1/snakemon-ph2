#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& Cell_Pos): Card(Cell_Pos)
{
	cardNumber = 2;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage( "Enter the value to be incremented" );
	AddedValue = pIn->GetInteger(pOut);
	if (AddedValue < 0)
	{
		int x, y;
		pOut->PrintMessage("Invalid, Click to continue...");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}

}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int newVal = pPlayer->GetWallet() - AddedValue;
	pPlayer->SetWallet(newVal);

}

CardTwo::~CardTwo()
{
}
