#include "CardNine.h"
#include <fstream>
CardNine::CardNine(const CellPosition& Cell_Pos): Card(Cell_Pos)
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput(); // returns an output pointer
	Input* pIn = pGrid->GetInput();    // returns an input pointer
	// we used an output pointer as the grid pointer has no accessibility on the cicked cell

	pOut->PrintMessage("CardNine:: choose the ToMove cel...");
	StoppingCell = pIn->GetCellClicked();
	if (!StoppingCell.IsValidCell() || StoppingCell.GetCellNum() == this->GetPosition().GetCellNum())
	{
		int x, y;
		pOut->PrintMessage("Invalid cell, Click to continue...");
		pIn->GetPointClicked(x, y);

	}
	pOut->ClearStatusBar(); // clear for the next operation

}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	if (StoppingCell.IsValidCell() || !(StoppingCell.GetCellNum() == this->GetPosition().GetCellNum()))
	{
		int newposition = StoppingCell.GetCellNum() - (pPlayer->GetCell()->GetCellPosition().GetCellNum()); //calculating what cells u gotta move 

		pPlayer->Move(pGrid, newposition);

	}



}

void CardNine::save(ofstream& output)
{
	Card::save(output);
	output << " " << StoppingCell.GetCellNumFromPosition(StoppingCell) << endl;
}

CardNine::~CardNine()
{
}
