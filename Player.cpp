#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->prevented = false;
	// Make all the needed initialization or validations
	this->justRolledDiceNum = -1;
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet < 0) this->wallet = 0;
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetPlayerNumber() const
{
	return this->playerNum;
}

int Player::GetJustRolledDiceNumber() const {
	return this->justRolledDiceNum;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

void Player::PreventPlaying()
{
	prevented = true;
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{
	if (prevented) {
		prevented = false;
		turnCount++;
		if (turnCount == 3) turnCount = 0;
		justRolledDiceNum = 0;
		pGrid->PrintErrorMessage("You are denied from playing this turn. Click to continue...");
		return;
	}
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	this->justRolledDiceNum = diceNumber;
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	this->turnCount++;
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (this->turnCount == 3) {
		turnCount = 0;
		pGrid->PrintErrorMessage("It's Time to recharge the wallet for Player " + to_string(GetPlayerNumber()) + " . Click to continue...");
		this->wallet += 10 * diceNumber;
		pOut->PrintMessage("The Money of Player: " + to_string(playerNum) + " has been Increased By: " + to_string(diceNumber * 10));
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	this->justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = pCell->GetCellPosition();
	int newCellNum = pos.GetCellNumFromPosition(pos) + diceNumber;
	if (newCellNum > 99) newCellNum = 99;
	CellPosition newPos = pos.GetCellPositionFromNum(newCellNum);
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, newPos);
	// 6- Apply() the game object of the reached cell (if any)
	if (pCell->GetGameObject() != NULL)
		pCell->GetGameObject()->Apply(pGrid, this);
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (newCellNum == 99) {
		pGrid->SetEndGame(true);
		pGrid->PrintErrorMessage("The Game Has finished! Player : " + to_string(GetPlayerNumber()) + " Won!");
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::ResetPlayer()
{
	wallet = 100;
	turnCount = 0;
}
