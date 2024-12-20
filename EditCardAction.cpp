#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"

EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
    // Initializes the pManager pointer of Action with the passed pointer
}


void EditCardAction::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Click on the source cell to edit");
    cardPos = pIn->GetCellClicked();

    if (cardPos.HCell() == -1)
    {
        pGrid->PrintErrorMessage("Please click on a valid cell. Click to continue...");
        return;
    }

    pCard = pGrid->GetCardFromPosition(cardPos);
    if (!pCard)
    {
        pGrid->PrintErrorMessage("Error: The cell does not contain a card! Click to continue...");
        pCard = nullptr;
        return;
    }

    if (!pCard->TakesParameters())
    {
        pGrid->PrintErrorMessage("Error: The card in the cell does not take parameters! Click to continue...");
        pCard = nullptr;
        return;
    }

    pOut->ClearStatusBar();
}

void EditCardAction::Execute()
{
    ReadActionParameters();

    if (!pCard) // If no valid card is selected, cancel the operation
        return;

    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    // Prompt the user to enter parameters specific to the card type
    pOut->PrintMessage("Enter the parameters for the card: ");
    pCard->EditParameters(pGrid, pIn, pOut);
    pOut->PrintMessage("Card edited successfully!");
}

EditCardAction::~EditCardAction()
{
}