#pragma once
#include "MonopolyCards.h"
class CardEleven : public MonopolyCards
{
private:
	static int price;
	static int fees;
	static Player* pPlayer;
public:
	CardEleven(const CellPosition& pos);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
	~CardEleven();
};

