#pragma once
#include "Comon.h"
#include "IBoardToCapStack.h"
#include "IBoardToJudge.h"

using namespace sf;



class Board :
	public IBoardToCapStack,
	public IBoardToJudge
{

public:

	Board(Vector2f size);
	void DrawBoard(RenderWindow& Window); //отрисовка поля
	void CheckSelctedElement(Vector2i MousePos); //проверка выбранной клетки
	bool SetDefaultStage(); // сброс доски по умолчанию

	void SetLocationSelected(int x, int y) override; // задать позицю
	Vector2f GetLocationSelected() override;
	void ResetSelected() override;
	void UpdateCapMap(Vector2f* stack, eCap side) override;
	void SetSelectedColor(Color Color) override;
	void ShowAllowedMove(Vector2f possition, eCap side) override;
	void ResetAllowedMove() override;

	int** GetCapMap() override;
	

private:

	bool GetTextureAndImage();


	int m_CapMap[BOARD_SIZE][BOARD_SIZE];

	Texture* GetTextureFromEnum(eBoardColor eBoardColor);

	RectangleShape m_Sprite_BoardMap[BOARD_SIZE][BOARD_SIZE];
	RectangleShape* m_SelectedSprite;

	Vector2f m_LocationSelected;
	Vector2f m_BoardPixelSize;

	Texture m_Texture_White;
	Texture	m_Texture_Gray;


};

