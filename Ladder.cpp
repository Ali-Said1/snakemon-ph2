#include "Ladder.h"
#include "Snake.h"
#include "Grid.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}


//bool Ladder::thisColumnHasLadder(const CellPosition& startPos, const CellPosition& endPos) const {
//	for (int i = startPos.VCell(); i > endPos.VCell(); i--) {
//		if (dynamic_cast<Ladder*>(CellList[i][startPos.HCell()]->GetGameObject()) != NULL)
//			return true;
//	}
//	return false;
//}
//
//bool Ladder::thisColumnHasSnake(const CellPosition& startPos, const CellPosition& endPos) const {
//	for (int i = startPos.VCell(); i < endPos.VCell(); i++) {
//		if (dynamic_cast<Snake*>(CellList[i][startPos.HCell()]->GetGameObject()) != NULL)
//			return true;
//	}
//	return false;
//}

Ladder::~Ladder()
{
}
