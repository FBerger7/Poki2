#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

class Menu
{
	enum Direction {
		DOWN = 2,
		UP
	};
	Sprite KursorSprite; //battle background
	Texture KursorTexture;
	Sprite MenuSprite;
	Texture MenuTexture;
	Text Money;
	Font font;
	int pozycja_y = 0;


public:
	Sprite getSprite();
	void move(int kierunek);
	void ustaw_pieniadze(int pieniadze, int x, int y);
	void ustaw_pozycje(int x, int y);
	int getPozycja();
	void draw(RenderWindow &m_Window);
	Menu();
	~Menu();
};
