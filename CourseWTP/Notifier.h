#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "Comon.h"
#include <sstream>

class Notifier
{

public:

	Notifier(String FontFileName);

	void Notify(RenderWindow& window);

	void UpCurrentHoop() { m_nCurrentHoop++; };

	void ResetHoop() { m_nCurrentHoop = 1; }

	void NotifyWinner(RenderWindow& window);

	bool isWinnerNotifyClick(Vector2i MousePos);

private:
	

	int m_nCurrentHoop;

	Font m_Font;

	Text* m_Text;

	Text* m_TextCurrentHoop;

	Text* m_TextWinnerIs;

	RectangleShape m_Rectangle;

};

