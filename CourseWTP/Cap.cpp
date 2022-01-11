#include "Cap.h"

void  CapCircle::SetLocation(int x, int y)
{
	m_Location.x = x;
	m_Location.y = y;

	setPosition(150 * m_Location.y + 5, 150 * m_Location.x + 5);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Vector2f& CapCircle::GetLocation()
{
	return m_Location;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CapStack::CapStack(eCap side, IBoardToCapStack& Board, IJudgeToCap& Judge) :
	m_Side(side),
	m_Board(Board),
	m_Judge(Judge)
{
	if (GetTextureAndImage())
	{
		cout << "CapStack - " << side << "initialized" << endl;
		SetToDefault();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CapStack::GetTextureAndImage()
{

	bool bOpen = false;


	switch (m_Side)
	{
	case eCAP_1:
		if (m_Texture.loadFromFile("skins/cap1.jpg"))
			bOpen = true;
		break;

	case eCAP_2:
		if (m_Texture.loadFromFile("skins/cap2.jpg"))
			bOpen = true;
			break;
	}


	if (bOpen)
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			m_CapCircle_CapStack[i].setRadius((150 / 2) - 5);
			m_CapCircle_CapStack[i].setTexture(&m_Texture);
		}
	}

	return bOpen;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CapStack::SetToDefault()
{

	switch (m_Side)
	{
	case eCAP_1:
		m_CapCircle_CapStack[0].SetLocation(0, 0);
		m_CapCircle_CapStack[1].SetLocation(0, 2);
		m_CapCircle_CapStack[2].SetLocation(3, 1);
		m_CapCircle_CapStack[3].SetLocation(3, 3);
		break;

	case eCAP_2:
		m_CapCircle_CapStack[0].SetLocation(0, 1);
		m_CapCircle_CapStack[1].SetLocation(0, 3);
		m_CapCircle_CapStack[2].SetLocation(3, 0);
		m_CapCircle_CapStack[3].SetLocation(3, 2);
		break;
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		
	}

	UpdateMap();
	m_Board.UpdateCapMap(m_CapMap, m_Side);
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CapStack::CheckSelctedElement(Vector2i MousePos)
{
	bool bFound = false;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (m_CapCircle_CapStack[i].getGlobalBounds().contains(MousePos.x, MousePos.y))
		{
			bFound = true;
			if (m_CapCircle_CapStack[i].getFillColor() == Color::Red)
			{
				m_CapCircle_CapStack[i].setFillColor(Color::White);
				m_SelectedCapCircle = NULL;
				m_Board.ResetAllowedMove();
				//return;
			}
			else if (m_SelectedCapCircle)
			{
				m_SelectedCapCircle->setFillColor(Color::White);
				m_SelectedCapCircle = &m_CapCircle_CapStack[i];
				m_SelectedCapCircle->setFillColor(Color::Red);
				m_Board.ResetAllowedMove();
			}
			else
			{
				m_SelectedCapCircle = &m_CapCircle_CapStack[i];
				m_SelectedCapCircle->setFillColor(Color::Red);
				//m_Board.SetSelectedColor(Color::Green);
			}
		}
	}

	if (bFound && m_SelectedCapCircle != NULL)
	{
		Vector2f currentPos = m_SelectedCapCircle->GetLocation();
		m_Board.ShowAllowedMove(currentPos, m_Side);
	}

	if (m_SelectedCapCircle != NULL && bFound != true)
	{
		Vector2f oldPos = m_SelectedCapCircle->GetLocation();
		Vector2f newPos = m_Board.GetLocationSelected();

		if (m_Judge.IsMoveAllowed(oldPos.x, oldPos.y, newPos.x , newPos.y))
		{
			m_SelectedCapCircle->SetLocation(newPos.x, newPos.y);
			m_SelectedCapCircle->setFillColor(Color::White);
			m_SelectedCapCircle = NULL;
			//m_Board.ResetSelected();


			UpdateMap();
			m_Board.ResetAllowedMove();
			m_Board.UpdateCapMap(m_CapMap, m_Side);
			return true;
		}
		else
		{
			//m_Board.SetSelectedColor(Color::White);
			//Vector2f& pos = m_SelectedCapCircle->GetLocation();
			//m_Board.SetLocationSelected(pos.x, pos.y);
		}
	
	} 
	
	return false;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CapStack::DrawStack(RenderWindow& Window)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		Window.draw(m_CapCircle_CapStack[i]);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CapStack::UpdateMap()
{
	cout << "UpdateMap Stack - " << m_Side << " = ";
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		m_CapMap[i] = m_CapCircle_CapStack[i].GetLocation();

		cout << m_CapMap[i].x << ";" << m_CapMap[i].y << ", ";
	}
	cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////