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
	virtual bool UserInputValidation();
	void Apply(Grid* pGrid, Player* pPlayer);
	virtual Card* CopyCard(CellPosition& pos);
	virtual bool EditParameters(Grid* pGrid);
	virtual void save(ofstream& output);
	virtual void load(ifstream& input);
	static void resetOwnerShip();
	~CardThirteen();
};

