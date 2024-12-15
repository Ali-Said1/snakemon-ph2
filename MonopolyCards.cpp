#include "MonopolyCards.h"

MonopolyCards::MonopolyCards(const CellPosition& pos) : Card(pos) {};

int MonopolyCards::ReadCardPrice(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int price = -1;
	do {
		pOut->PrintMessage("Input price of the station...");
		price = pIn->GetInteger(pOut);
	} while (price <= 0);
	return price;
}

int MonopolyCards::ReadCardFees(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int fees = -1;
	do {
		pOut->PrintMessage("Input fees of the station...");
		fees = pIn->GetInteger(pOut);
	} while (fees <= 0);
	return fees;
}
