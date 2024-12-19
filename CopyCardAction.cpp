#include "CopyCardAction.h"
#include"Grid.h"
#include"Output.h"
#include "Input.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp):Action(pApp)
{

}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the source cell");
	CardPos = pIn->GetCellClicked(); // brings us an objet for the cell (if valid) from the mouse click if not :: returns (-1,-1) 
	if (CardPos.HCell() == -1) // no need to check for the vcell as if invalid we will alsp get  -1 there 
	{
		pGrid->PrintErrorMessage("Please click on a valid cell, Click to continue...");
	}

}

void CopyCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	pCard = pGrid->
	/*if (pCard == NULL)
	{
		pOut->PrintMessage("There is no card here!");
	}
	else {
		pGrid->SetClipboard(pCard);
		pOut->PrintMessage("Card Copied!");
	}*/
}

CopyCardAction::~CopyCardAction()
{

}


