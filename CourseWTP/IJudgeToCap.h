#pragma once
#include "Comon.h"

class IJudgeToCap
{
public:

	virtual bool IsMoveAllowed(int OLDx, int OLDy, int NEWx, int NEWy) = 0;

};

