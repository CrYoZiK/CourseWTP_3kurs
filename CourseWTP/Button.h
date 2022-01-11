#pragma once
#include "Comon.h"

class Button
{

public:

	Button(Font& font, string label);

	void DrawButton(RenderWindow& window);

	bool IsClicked(Vector2i MousePos);

private:

	RectangleShape Rectangle;

	Text Label;

};

