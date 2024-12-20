#include "CardFive.h"
#include <fstream>
CardFive::CardFive(const CellPosition& pos) : Card(pos) {
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	pPlayer->Move(pGrid, pPlayer->GetJustRolledDiceNumber());
}

void CardFive::save(ofstream& output)
{
	Card::save(output);
	output << endl;
}

CardFive:: ~CardFive() {}