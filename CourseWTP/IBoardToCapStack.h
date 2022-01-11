#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "Comon.h"

using namespace sf;

class IBoardToCapStack
{
public:

	virtual void SetLocationSelected(int x, int y) = 0;

	virtual Vector2f GetLocationSelected() = 0;

	virtual void ResetSelected() = 0;

	virtual void UpdateCapMap(Vector2f* stack, eCap side) = 0;

	virtual void SetSelectedColor(Color Color) = 0;

	virtual void ShowAllowedMove(Vector2f possition, eCap side) = 0;

	virtual void ResetAllowedMove() = 0;

};

