#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Menu_walki
{
	enum Direction {
		RIGHT,
		LEFT,
		DOWN,
		UP};
	Sprite KursorSprite; //battle background
	Texture KursorTexture;
	int pozycja_x;
	int pozycja_y;


public:
	Sprite getSprite();
	void move(int kierunek);
	Menu_walki();
	~Menu_walki();
};

