#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) {
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	pPlayer->Move(pGrid, -pPlayer->GetJustRolledDiceNumber());
}

CardSix:: ~CardSix() {}