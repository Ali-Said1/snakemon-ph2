#include "Card.h"


Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	if (cardNumber >= 1 || cardNumber <= 13)
		cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

bool Card::TakesParameters() const
{
	// Default implementation: Cards that don't take parameters return false
	return false;
}

void Card::EditParameters(Grid* pGrid, Input* pIn, Output* pOut)
{
	// Default implementation: Cards that don't take parameters do nothing
	pOut->PrintMessage("This card does not support editing parameters.");
}


void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
	Input* pIn = pGrid->GetInput();
	int x, y;
	pIn->GetPointClicked(x, y);
}

Card::~Card()
{
}