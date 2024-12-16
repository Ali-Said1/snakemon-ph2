#include "Snake.h"
#include "Grid.h"
#include "ladder.h"

Snake::Snake(const CellPosition& startCellPos1, const CellPosition& endCellPos1):GameObject(startCellPos1)
{
	this->endCellPos = endCellPos1;

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
    //lesa
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("You have reached a snake. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}



Snake::~Snake()
{
}
