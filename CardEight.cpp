#include "CardEight.h"
CardEight::CardEight(const CellPosition& Cell_Pos) : Card(Cell_Pos) {
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	// Reads Nothing
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	//pGrid->PrintErrorMessage("This card prevents player " + to_string(pPlayer->GetPlayerNumber()) + " from rolling next turn. Click to continue...");
	//already in the apply function.
	pPlayer->Move( pGrid , 0 );
}

CardEight::~CardEight()
{

}

