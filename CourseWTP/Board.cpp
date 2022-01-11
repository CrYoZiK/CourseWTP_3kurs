#include "Board.h"




Board::Board(Vector2f size):
	m_BoardPixelSize(size),
	m_SelectedSprite(NULL)
{

	if (GetTextureAndImage())
	{
		std::cout << "texture load successefull" << std::endl;

		if (SetDefaultStage())
		{
			std::cout << "Successefull loading sprite" << std::endl;
		}
		else
		{
			std::cout << "sprite load error" << std::endl;
		}
	}
	else
	{
		std::cout << "texture load error" << std::endl;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Board::GetTextureAndImage()
{
	if (!m_Texture_White.loadFromFile("skins/test1.jpg") ||
		!m_Texture_Gray.loadFromFile("skins/test2.jpg")
		)
	{
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Board::SetDefaultStage()
{

	eBoardColor eBoardColor = eBOARD_DEFAULT;
	Vector2f pos;
	pos.x = 0;
	pos.y = 0;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		pos.y = i * m_BoardPixelSize.y;
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			pos.x = j * m_BoardPixelSize.x;
			if (i % 2 == 1 && j == 0)
			{
				eBoardColor = eBOARD_WHITE;
			}
			else if (i % 2 == 0 && j == 0)
			{
				eBoardColor = eBOARD_GRAY;
			}
			else if (eBoardColor == eBOARD_GRAY)
			{
				eBoardColor = eBOARD_WHITE;
			}
			else if (eBoardColor == eBOARD_WHITE)
			{
				eBoardColor = eBOARD_GRAY;
			}

			std::cout << "m_Sprite_BoardMap[" << i << "][" << j << "] color = " << eBoardColor << std::endl;
			std::cout << "position = [" << pos.x << ";" << pos.y << "]" << std::endl;
			m_Sprite_BoardMap[i][j].setSize(m_BoardPixelSize);
			m_Sprite_BoardMap[i][j].setTexture(GetTextureFromEnum(eBoardColor));
			m_Sprite_BoardMap[i][j].setPosition(pos);

		}
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Texture* Board::GetTextureFromEnum(eBoardColor eBoardColor)
{
	Texture Texture;

	switch (eBoardColor)
	{
	case eBOARD_WHITE:
		return &m_Texture_White;
		break;
	case eBOARD_GRAY:
		return &m_Texture_Gray;
		break;
	}

	return &Texture;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Board::DrawBoard(RenderWindow& Window)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Window.draw(m_Sprite_BoardMap[i][j]);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Board::CheckSelctedElement(Vector2i MousePos)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			//m_CapMap[i][j] = DefCapMap[i][j];

			if (m_Sprite_BoardMap[i][j].getGlobalBounds().contains(MousePos.x, MousePos.y))
			{
				/*
				if (m_Sprite_BoardMap[i][j].getFillColor() == Color::Green)
				{
					m_Sprite_BoardMap[i][j].setFillColor(Color::White);
					m_SelectedSprite = NULL;
					return;
				}
				if (m_SelectedSprite)
				{
					m_SelectedSprite->setFillColor(Color::White);
					m_SelectedSprite = NULL;
				}
				*/

				m_SelectedSprite = &m_Sprite_BoardMap[i][j];
				SetLocationSelected(i, j);
				//m_SelectedSprite->setFillColor(Color::Green);
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Board::SetLocationSelected(int x, int y)
{
	m_LocationSelected.x = x;
	m_LocationSelected.y = y;
}

Vector2f Board::GetLocationSelected()
{
	return m_LocationSelected;
}

void Board::ResetSelected()
{
	//m_SelectedSprite->setFillColor(Color::White);
	m_SelectedSprite = NULL;
}

void Board::UpdateCapMap(Vector2f* stack, eCap side)
{

	cout << "BOARD == UpdateMap Stack - " << side << " = ";
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (m_CapMap[i][j] == side)
			{
				m_CapMap[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		int x = stack[i].x;
		int y = stack[i].y;
		cout << x << ";" << y << ", ";

		m_CapMap[x][y] = side;
	}
	cout << endl;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << m_CapMap[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}


void Board::SetSelectedColor(Color Color)
{
	m_SelectedSprite->setFillColor(Color);
}


int** Board::GetCapMap()
{

	int** Map = new int* [BOARD_SIZE];

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		Map[i] = new int(0);
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Map[i][j] = m_CapMap[i][j];
		}
	}
	return Map;
}



void Board::ShowAllowedMove(Vector2f possition, eCap side)
{
	int xV, yV;

	xV = possition.x - 1;
	yV = possition.y;

	if ((0 <= xV && xV <= 3) && (0 <= yV && yV <= 3))
	{
		if (m_CapMap[xV][yV] == 0)
		{
			m_Sprite_BoardMap[xV][yV].setFillColor(Color::Green);
		}
	}

	xV = possition.x;
	yV = possition.y - 1;

	if ((0 <= xV && xV <= 3) && (0 <= yV && yV <= 3))
	{
		if (m_CapMap[xV][yV] == 0)
		{
			m_Sprite_BoardMap[xV][yV].setFillColor(Color::Green);
		}
	}

	xV = possition.x + 1;
	yV = possition.y;

	if ((0 <= xV && xV <= 3) && (0 <= yV && yV <= 3))
	{
		if (m_CapMap[xV][yV] == 0)
		{
			m_Sprite_BoardMap[xV][yV].setFillColor(Color::Green);
		}
	}

	xV = possition.x;
	yV = possition.y + 1;

	if ((0 <= xV && xV <= 3) && (0 <= yV && yV <= 3))
	{
		if (m_CapMap[xV][yV] == 0)
		{
			m_Sprite_BoardMap[xV][yV].setFillColor(Color::Green);
		}
	}
}


void Board::ResetAllowedMove()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			m_Sprite_BoardMap[i][j].setFillColor(Color::White);
		}
	}
}