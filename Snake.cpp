#include "Snake.h"
#include "Grid.h"
#include "ladder.h"

Snake::Snake(const CellPosition& startCellPos1, const CellPosition& endCellPos1):GameObject(startCellPos1)
{
	this->endCellPos = endCellPos1;

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
    //still val
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

bool Snake::IsOverlapping(GameObject* newObj) const
{
	if (this->GetPosition().HCell() != newObj->GetPosition().HCell()) return false;
	Ladder* L1 = dynamic_cast<Ladder*>(newObj);
	if (L1)
	{
		if ((this->GetPosition().VCell() <= newObj->GetPosition().VCell() && this->GetPosition().VCell() >= L1->GetEndPosition().VCell()) || (this->GetEndPosition().VCell() <= newObj->GetPosition().VCell() && this->GetEndPosition().VCell() >= L1->GetEndPosition().VCell()))
		{

			return true;
		}
		return false;
	}
	else
	{
		Snake* S1 = dynamic_cast<Snake*>(newObj);
		if (this->GetPosition().VCell() == S1->GetPosition().VCell() || this->GetPosition().VCell() == S1->GetEndPosition().VCell() || this->GetEndPosition().VCell() == S1->GetPosition().VCell())
		{
			return true;
		}
		return false;
	}
	

}



Snake::~Snake()
{
}
