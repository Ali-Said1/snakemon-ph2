#pragma once
#include "Card.h"
// Functionality ::  Move the player stopping on this card to a specific cell. This specific cell is
//                   specified when adding the card to the grid in the design mode.
// Inputs        ::  Cell to be moved to.
class CardNine : public Card
{
	CellPosition StoppingCell;
public :
	CardNine(const CellPosition& Cell_Pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void save(ofstream& output);
	virtual void load(ifstream& input);
	virtual ~CardNine();
};

