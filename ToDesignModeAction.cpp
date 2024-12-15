#include "ToDesignModeAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp) {};
ToDesignModeAction::~ToDesignModeAction() {};
void ToDesignModeAction::ReadActionParameters() {};

void ToDesignModeAction::Execute() {
	UI.InterfaceMode = MODE_DESIGN;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}