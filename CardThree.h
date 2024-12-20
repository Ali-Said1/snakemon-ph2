#pragma once
#include "Card.h"
#include"Ladder.h"

/*
Card3:
 ● Moves the player forward to the start of the next ladder. (If no ladders ahead, do nothing)
 ● Input data: None.
*/

class CardThree : public Card
{

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads nothing
	virtual bool UserInputValidation();
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	// by moving the player to the next ladder and apply the ladder;
	virtual void save(ofstream& output);

	virtual ~CardThree(); // A Virtual Destructor
};