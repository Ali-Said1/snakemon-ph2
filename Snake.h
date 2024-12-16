#pragma once
#include "GameObject.h"
class Snake : public GameObject 
{
private :
	CellPosition endCellPos; //represents the end of the cell position 


public :
	Snake(const CellPosition& startCellPos1, const CellPosition& endCellPos1);
	virtual void Draw(Output* pOut) const;
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	CellPosition GetEndPosition() const;
	CellPosition Ladder::GetEndPosition() const
	{
		return endCellPos;
	}

	bool Snake::IsOverlapping(GameObject* newObj) const
	{
		if (this->GetPosition().HCell() != newObj->GetPosition().HCell()) return false;
		Ladder* L1 = dynamic_cast<Ladder*>(newObj);
		if (L1)
		{
			if ((this->GetPosition().VCell() <= newObj->GetPosition().VCell() && this->GetPosition().VCell() >= L1->GetEndPosition().VCell()) || (this->GetEndPosition().VCell() <= newObj->GetPosition().VCell() && this->GetEndPosition().VCell() >= L1->GetEndPosition().VCell()))
			{

				return true;
			}
			return false;
		}
		else
		{
			Snake* S1 = dynamic_cast<Snake*>(newObj);
			if (this->GetPosition().VCell() == S1->GetPosition().VCell() || this->GetPosition().VCell() == S1->GetEndPosition().VCell() || this->GetEndPosition().VCell() == S1->GetPosition().VCell())
			{
				return true;
			}
			return false;
		}
	}

	virtual ~Snake();

};

