#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "Board.h"
#include "Cap.h"
#include "Judge.h"
#include "Notifier.h"
#include "InfoPanel.h"
#include <sstream>
#include "Button.h"

using namespace std;
using namespace sf;


int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 802), "SFMLworks");
	window.setFramerateLimit(60);
	Vector2f size;
	size.x = 150;
	size.y = 150;

	Board Board(size);
	Judge Judge(Board);
	CapStack CapStack1(eCAP_1, Board, Judge);
	CapStack CapStack2(eCAP_2, Board, Judge);
	Notifier Notifier("font/timesnewromanpsmt.ttf");
	InfoPanel InfoPanel;

	Font FontButton;
	FontButton.loadFromFile("font/timesnewromanpsmt.ttf");


	Button button_restart(FontButton, "Restart");

	bool bWinner = false;

	bool bHoop = false;
	CapStack* currentCapStack = &CapStack1;
	Vector2i MousePos;



	while (window.isOpen())
	{
		MousePos = Mouse::getPosition(window);
		sf::Event event;



		while (window.pollEvent(event))
		{
			if (bHoop)
			{
				if (currentCapStack->GetSide() == eCAP_1)
				{
					currentCapStack = &CapStack2;
					bHoop = false;
				}
				else if (currentCapStack->GetSide() == eCAP_2)
				{
					currentCapStack = &CapStack1;
					bHoop = false;
				}
			}



			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
			if (event.key.code == Mouse::Left)
			{
				cout << "Mouse click on position " << MousePos.x << ";" << MousePos.y << endl;

				if (Notifier.isWinnerNotifyClick(MousePos) && bWinner)
				{
					bWinner = false;
					Notifier.ResetHoop();
					CapStack1.SetToDefault();
					CapStack2.SetToDefault();
					currentCapStack = &CapStack1;
				}

				if (button_restart.IsClicked(MousePos))
				{
					Notifier.ResetHoop();
					CapStack1.SetToDefault();
					CapStack2.SetToDefault();
					Board.ResetAllowedMove();
					Board.ResetSelected();
					currentCapStack = &CapStack1;
				}

				Board.CheckSelctedElement(MousePos);
				bHoop = currentCapStack->CheckSelctedElement(MousePos);
			}

			if (bHoop == true)
			{
				Notifier.UpCurrentHoop();
				if (Judge.CheckWiner())
				{
					bWinner = true;
				}
			}
			
		}


		window.clear();

		if (bWinner)
		{
			Notifier.NotifyWinner(window);
		}
		else
		{
			Board.DrawBoard(window);
			CapStack1.DrawStack(window);
			CapStack2.DrawStack(window);
			InfoPanel.DrawPanel(window);
			Notifier.Notify(window);

			button_restart.DrawButton(window);
		}

		window.display();
	}

	return 0;
}