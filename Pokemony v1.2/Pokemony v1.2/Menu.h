#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Menu
{
	enum Direction {
		DOWN,
		UP
	};
	Sprite KursorSprite; //battle background
	Texture KursorTexture;
	Sprite MenuSprite;
	Texture MenuTexture;
	int pozycja_x;
	int pozycja_y;


public:
	Sprite getSprite();
	void move(int kierunek);
	void ustaw_pozycje(int x, int y);
	void draw(RenderWindow &m_Window);
	Menu();
	~Menu();
};
