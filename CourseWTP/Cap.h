#pragma once
#include "Comon.h"
#include "Board.h"
#include "Judge.h"

#include "ICapJudge.h"
#include "IBoardToCapStack.h"
#include "IJudgeToCap.h"

using namespace sf;


class CapCircle : public CircleShape
{

public:

	//eCap CapSide;
	void SetLocation(int x, int y);
	Vector2f& GetLocation();

private:

	Vector2f m_Location;
	
};


class CapStack :
	public ICapJudge
{
public:

	CapStack(eCap side, IBoardToCapStack& Board, IJudgeToCap& Judge);

	void SetToDefault() override;

	bool CheckSelctedElement(Vector2i MousePos);

	void DrawStack(RenderWindow& Window);

	eCap GetSide() { return m_Side; };


private:
	
	void UpdateMap();

	bool GetTextureAndImage();

	eCap m_Side;

	CapCircle m_CapCircle_CapStack[BOARD_SIZE];

	Vector2f m_CapMap[BOARD_SIZE];

	CapCircle* m_SelectedCapCircle;

	Texture m_Texture;

	IBoardToCapStack& m_Board;
	IJudgeToCap& m_Judge;
};


