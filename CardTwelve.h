#pragma once
#include "MonopolyCards.h"
class CardTwelve : public MonopolyCards
{
private:
	static int price;
	static int fees;
	static Player* pPlayer;
public:
	CardTwelve(const CellPosition& pos);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
	virtual void save(ofstream& output);
	virtual void load(ifstream& input);
	~CardTwelve();
};

