#include "CardEleven.h"
#include <fstream>
CardEleven::CardEleven(const CellPosition& pos) : MonopolyCards(pos) { cardNumber = 11; }
CardEleven::~CardEleven() {}

int CardEleven::fees = 0;
int CardEleven::price = 0;
Player* CardEleven::pPlayer = NULL;

void CardEleven::ReadCardParameters(Grid* pGrid) {
	if (price != 0 && fees != 0) return;
	price = ReadCardPrice(pGrid); // Call the functions of the parent class (MonopolyCards)
	fees = ReadCardFees(pGrid);
}
bool CardEleven::UserInputValidation()
{
	if (price <= 0 || fees <= 0)
		return false;
	return true;
}
void CardEleven::Apply(Grid* pGrid, Player* pPlayer) {
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
		this->pPlayer->SetWallet(this->pPlayer->GetWallet() + fees);
		pPlayer->SetWallet(pPlayer->GetWallet() - fees);
		return;
	}
}

Card* CardEleven::CopyCard(CellPosition& pos)
{
	return new CardEleven(pos);
}

bool CardEleven::EditParameters(Grid* pGrid)
{
	int f = this->fees;
	int p = this->price;
	price = ReadCardPrice(pGrid);
	fees = ReadCardFees(pGrid);
	if (price == -1 || fees == -1) {
		price = p;
		fees = f;
		return false;
	}
	return true;
}

void CardEleven::save(ofstream& output) {
	Card::save(output);
	output << " " << price << " " << fees << endl;
}

void CardEleven::load(ifstream& input) {
	int p, f;
	input >> p >> f;
	this->price = p;
	this->fees = f;
}

void CardEleven::resetOwnerShip()
{
	pPlayer = NULL;
}
