#include "AddSnakeAction.h"
#include "Output.h"
#include "Input.h"
#include "Snake.h"


AddSnakeAction::AddSnakeAction(ApplicationManager* pApp): Action(pApp)
{
	// initializing the pointer of the AppManager with the base calss
}

void AddSnakeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the snake’s start cell...");
	Start_Pos = pIn->GetCellClicked();
	pOut->PrintMessage("Click on the snake’s end cell...");
	End_Pos = pIn->GetCellClicked();
	
	
	if (Start_Pos.VCell() == 8 )
	{
		pGrid->PrintErrorMessage("Error: The starting cell cannot be in the first row! Click to continue ...");
		Start_Pos = CellPosition(-1, -1);

	}
	else if (Start_Pos.HCell() != End_Pos.HCell()) {
		pGrid->PrintErrorMessage("Error: The ending cell and the starting cell are not in the same column! Click to continue...");
		Start_Pos = CellPosition(-1, -1);
	}
	else if (Start_Pos.VCell() > End_Pos.VCell()) {

		pGrid->PrintErrorMessage("Error: The ending cell cannot be above the starting cell! Click to continue...");
		Start_Pos = CellPosition(-1, -1);
	}
	else if (Start_Pos.HCell() == End_Pos.HCell() && Start_Pos.VCell() == End_Pos.VCell())
	{
		pGrid->PrintErrorMessage("Error: The starting cell and the ending cell are identical! Click to continue ...");
		Start_Pos = CellPosition(-1, -1);
	}
	else if (Start_Pos.VCell() == 0 && End_Pos.HCell() == 10) {
		pGrid->PrintErrorMessage("Error: The starting cell cannot be in the final column of the final row! Click to continue ...");
	}
	pOut->ClearStatusBar();
}

void AddSnakeAction::Execute()
{
	ReadActionParameters();
	if (Start_Pos.HCell() == -1 || Start_Pos.VCell() == -1)
		return;

	Snake* pSnake = new Snake(Start_Pos, End_Pos);

	Grid* pGrid = pManager->GetGrid();
	bool Check_Addition = pGrid->AddObjectToCell(pSnake);

	if (!Check_Addition)
	{
	
		pGrid->PrintErrorMessage("Error: Can't add Ladder here! Click to continue ...");
		Input* pIn = pGrid->GetInput();
		int x, y;
		pIn->GetPointClicked(x ,y);

	}



}

AddSnakeAction::~AddSnakeAction()
{
}


