#pragma once
#include "MonopolyCards.h"
class CardThirteen : public MonopolyCards
{
private:
	static int price;
	static int fees;
	static Player* pPlayer;
public:
	CardThirteen(const CellPosition& pos);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
	virtual void save(ofstream& output);
	virtual void load(ifstream& input);
	~CardThirteen();
};

