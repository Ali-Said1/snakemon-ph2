#include "CardTen.h"

CardTen::CardTen(const CellPosition& pos) : MonopolyCards(pos) { cardNumber = 10; }
CardTen::~CardTen() {}

int CardTen::fees = 0;
int CardTen::price = 0;
Player* CardTen::pPlayer = NULL;

void CardTen::ReadCardParameters(Grid* pGrid) {
	if (price != 0 && fees != 0) return;
	price = ReadCardPrice(pGrid);
	fees = ReadCardFees(pGrid);
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (this->pPlayer == NULL) {
		pGrid->PrintErrorMessage("Would you like to buy this station for "+ to_string(this->price) + "? [y\\n]");
		string answer = pIn->GetSrting(pOut);
		while (answer != "n" && answer != "y") answer = pIn->GetSrting(pOut);
		if (answer == "y") {
			if (pPlayer->GetWallet() >= this->price) {
				int currentWallet = pPlayer->GetWallet();
				pPlayer->SetWallet(currentWallet - this->price);
				this->pPlayer = pPlayer;
				pGrid->PrintErrorMessage("You succefully bought station number " + to_string(this->cardNumber));
				return;
			}
			else {
				pGrid->PrintErrorMessage("You can't afford the current station.");
				return;
			}
		}
	}
	else {
		pGrid->PrintErrorMessage("You landed on the station owned by player " + to_string(this->pPlayer->GetPlayerNumber()) + ", A fee of " + to_string(fees) + "is to be paid. [Click ...]");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
}