#pragma once
#include "Comon.h"



class InfoPanel
{

public:

	InfoPanel();
	void DrawPanel(RenderWindow& window);

private:
	
	Texture m_Texture_Background;

	RectangleShape m_RectBackground;
};

