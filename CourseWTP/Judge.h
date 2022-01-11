#pragma once
#include "Comon.h"

#include "IJudgeToCap.h"
#include "IBoardToJudge.h"

using namespace sf;


class Judge :
	public IJudgeToCap
{

public:

	Judge(IBoardToJudge& Board);

	bool CheckWiner();

	bool IsMoveAllowed(int OLDx, int OLDy, int NEWx, int NEWy) override;

private:

	IBoardToJudge& m_Board;
};


