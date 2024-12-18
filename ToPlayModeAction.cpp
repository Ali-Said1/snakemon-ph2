#include "ToPlayModeAction.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp):Action(pApp)
{

}

void ToPlayModeAction::ReadActionParameters()
{

}

void ToPlayModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pManager->ExecuteAction(SAVE_GRID);
	pOut->CreatePlayModeToolBar();

}

ToPlayModeAction::~ToPlayModeAction()
{
}