#include "Button.h"


Button::Button(Font& font, string label)
{
	Label.setFont(font);
	Label.setCharacterSize(25);
	Label.setString(label);
	Label.setFillColor(Color::Black);
	Label.setStyle(Text::Bold);


	Rectangle.setPosition(414, 622);
	Vector2f size;
	size.x = 164;
	size.y = 40;
	Rectangle.setSize(size);
	Rectangle.setFillColor(Color::White);
	Rectangle.setOutlineColor(Color::Black);
	Rectangle.setOutlineThickness(2);

	

	Label.setPosition(455, 625);

	Vector2f check = Label.getOrigin();

	cout << "check label origin " << check.x << ";" << check.y << endl;
}


void Button::DrawButton(RenderWindow& window)
{
	window.draw(Rectangle);
	window.draw(Label);
}


bool Button::IsClicked(Vector2i MousePos)
{
	bool bClicked = false;

	if (Rectangle.getGlobalBounds().contains(MousePos.x, MousePos.y))
	{
		bClicked = true;
	}

	return bClicked;
}