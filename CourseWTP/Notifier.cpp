#include "Notifier.h"


Notifier::Notifier(String FontFileName) :
	m_nCurrentHoop(1),
	m_Text(NULL),
	m_TextCurrentHoop(NULL),
	m_TextWinnerIs(NULL)
{
	if (m_Font.loadFromFile(FontFileName))
	{
		cout << "Font loaded" << endl;

		m_Text = new Text();
		m_Text->setFont(m_Font);
		m_Text->setCharacterSize(30);
		m_Text->setFillColor(Color::Magenta);
		m_Text->setStyle(Text::Bold);
		m_Text->setPosition(22, 625);
		//m_Text->setString("");

		
		m_TextCurrentHoop = new Text();
		m_TextCurrentHoop->setFont(m_Font);
		m_TextCurrentHoop->setCharacterSize(30);
		m_TextCurrentHoop->setFillColor(Color::Black);
		m_TextCurrentHoop->setStyle(Text::Bold);
		m_TextCurrentHoop->setPosition(22, 655);
		m_TextCurrentHoop->setString("");


		m_TextWinnerIs = new Text();
		m_TextWinnerIs->setFont(m_Font);
		m_TextWinnerIs->setCharacterSize(60);
		m_TextWinnerIs->setFillColor(Color::Magenta);
		m_TextWinnerIs->setStyle(Text::Bold);
		m_TextWinnerIs->setPosition(8, 360);
	}

	m_Rectangle.setPosition(0, 0);
	Vector2f size;
	size.x = 600;
	size.y = 802;
	m_Rectangle.setSize(size);
	m_Rectangle.setFillColor(Color::White);
	//m_Rectangle.setOutlineColor(Color::Black);
	//m_Rectangle.setOutlineThickness(2);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Notifier::Notify(RenderWindow& window)
{
	m_TextCurrentHoop = new Text();
	m_TextCurrentHoop->setFont(m_Font);
	m_TextCurrentHoop->setCharacterSize(30);
	m_TextCurrentHoop->setFillColor(Color::Black);
	m_TextCurrentHoop->setStyle(Text::Bold);
	m_TextCurrentHoop->setPosition(22, 655);
	m_TextCurrentHoop->setString("");

	if (m_nCurrentHoop % 2 == 1)
	{
		m_Text->setString(String("The first player's move", locale("US")));
	}
	else
	{
		m_Text->setString(String("The second player's move", locale("US")));
	}
	


	string str = "Step - " + to_string(m_nCurrentHoop);
	m_TextCurrentHoop->setString(String(str, locale("US")));



	window.draw(*m_TextCurrentHoop);
	window.draw(*m_Text);


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Notifier::NotifyWinner(RenderWindow& window)
{

	m_TextCurrentHoop = new Text();
	m_TextCurrentHoop->setFont(m_Font);
	m_TextCurrentHoop->setCharacterSize(60);
	m_TextCurrentHoop->setFillColor(Color::Black);
	m_TextCurrentHoop->setStyle(Text::Bold);
	m_TextCurrentHoop->setPosition(90, 410);
	m_TextCurrentHoop->setString("");

	if (m_nCurrentHoop % 2 == 0)
	{
		m_TextWinnerIs->setString(String("The first player won", locale("US")));
	}
	else
	{
		m_TextWinnerIs->setString(String("The second player won", locale("US")));
	}

	string str = "Total moves - " + to_string(m_nCurrentHoop - 1);
	m_TextCurrentHoop->setString(String(str, locale("US")));

	window.draw(m_Rectangle);
	window.draw(*m_TextWinnerIs);
	window.draw(*m_TextCurrentHoop);


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Notifier::isWinnerNotifyClick(Vector2i MousePos)
{
	bool bClicked = false;

	if (m_Rectangle.getGlobalBounds().contains(MousePos.x, MousePos.y))
	{
		bClicked = true;
	}

	return bClicked;
}