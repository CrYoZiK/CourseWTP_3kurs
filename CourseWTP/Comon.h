#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
const int BOARD_SIZE = 4;
const int PIXEL_BOARD_SIZE = 150;
using namespace std;
using namespace sf;

/*
int DefCapMap[BOARD_SIZE][BOARD_SIZE] = {
					{1, 2, 1, 2},
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{2, 1, 2, 1}
};
*/

enum eBoardColor
{
	eBOARD_DEFAULT = 0,
	eBOARD_WHITE,
	eBOARD_GRAY,
	eBOARD_SELECTED
};

enum eCap
{
	eCAP_DEF = 0,
	eCAP_1,
	eCAP_2
};