#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters

	//if (pGrid->GetCellFromCellPosition(startPos)->HasCard() != NULL)
	//{
	//	pGrid->PrintErrorMessage("Error: The starting cell cannot be a special type of cell (card cell). Click to continue ...");
	//	startPos = CellPosition(-1, -1);
	//	return;
	//}

	if (startPos.VCell() == 0)
	{
		pGrid->PrintErrorMessage("Error: The starting cell cannot be in the first row! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;
	}

	if (startPos.HCell() != endPos.HCell()) {
		pGrid->PrintErrorMessage("Error: The starting cell and the ending cell must be in the same column! Click to continue ...");
		startPos = CellPosition(-1, -1);
	}

	else if (startPos.VCell() < endPos.VCell()) {

		pGrid->PrintErrorMessage("Error: The ending cell must be after the starting cell! Click to continue ...");
		startPos = CellPosition(-1, -1);
	}

	else if (startPos.HCell() == endPos.HCell() && startPos.VCell() == endPos.VCell())
	{
		pGrid->PrintErrorMessage("Error: The starting cell and the ending cell are identical! Click to continue ...");
		startPos = CellPosition(-1, -1);
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}

AddLadderAction::~AddLadderAction()
{
}