#include "CardThirteen.h"
#include <fstream>

CardThirteen::CardThirteen(const CellPosition& pos) : MonopolyCards(pos) { cardNumber = 10; }
CardThirteen::~CardThirteen() {}

int CardThirteen::fees = 0;
int CardThirteen::price = 0;
Player* CardThirteen::pPlayer = NULL;

void CardThirteen::ReadCardParameters(Grid* pGrid) {
	if (price != 0 && fees != 0) return;
	price = ReadCardPrice(pGrid); // Call the functions of the parent class (MonopolyCards)
	fees = ReadCardFees(pGrid);
}

void CardThirteen::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);  // Output the default message
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (this->pPlayer == NULL) { // if the station wasn't bought by another player
		pGrid->PrintErrorMessage("Would you like to buy this station for " + to_string(this->price) + "? [y\\n]");
		string answer = pIn->GetSrting(pOut);
		while (answer != "n" && answer != "y") answer = pIn->GetSrting(pOut); // Loop until the user gives appropriate answer
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

void CardThirteen::save(ofstream& output)
{
	Card::save(output);
	output << " " << price << " " << fees << endl;
}
