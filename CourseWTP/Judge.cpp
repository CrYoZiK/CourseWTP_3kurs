#include "Judge.h"


Judge::Judge(IBoardToJudge& Board) :
	m_Board(Board)
{

}


bool Judge::IsMoveAllowed(int OLDx, int OLDy, int NEWx, int NEWy)
{
	if (
		abs(OLDx - NEWx) + abs(OLDy - NEWy) < 2
		)
	{
		int** CapMap = m_Board.GetCapMap();

		if (CapMap[NEWx][NEWy] == 0)
		{
			return true;
		}
	}
	return false;
}



bool Judge::CheckWiner()
{
	int** CapMap = m_Board.GetCapMap();
	std::cout << std::endl << "Check winner" << endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << CapMap[i][j] << ", ";

		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	int nOnGorizont = 0;
	int side = 0;
	bool bWinerFound = false;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		side = 0;
		nOnGorizont = 0;
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (CapMap[i][j] != 0)
			{
				if (side == CapMap[i][j])
				{
					nOnGorizont++;
				}
				else
				{
					side = CapMap[i][j];
					nOnGorizont = 1;
				}
			}
			else
			{
				side = 0;
				nOnGorizont = 0;
			}
			if (nOnGorizont >= 3)
			{
				bWinerFound = true;
				break;
			}
		}
		if (nOnGorizont >= 3)
		{
			bWinerFound = true;
			break;
		}
	}
	if (bWinerFound)
	{
		std::cout << "Winer is player " << side << std::endl;
	}

	return bWinerFound;

}