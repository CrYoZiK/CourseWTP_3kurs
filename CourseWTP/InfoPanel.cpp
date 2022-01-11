#include "InfoPanel.h"


InfoPanel::InfoPanel()
{
	if (m_Texture_Background.loadFromFile("skins/InfoPanel.jpg"))
	{
		cout << "InfoPanel success" << endl;
		m_RectBackground.setTexture(&m_Texture_Background);

		Vector2f size(600, 200);
		m_RectBackground.setSize(size);
		m_RectBackground.setPosition(0, 602);
		//m_RectBackground.setOutlineThickness(2);
		//m_RectBackground.setOutlineColor(Color::Black);
	}
}

void InfoPanel::DrawPanel(RenderWindow& window)
{
	window.draw(m_RectBackground);
}