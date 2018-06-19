#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

class Menu
{
protected:
	enum Direction {
		DOWN = 2,
		UP
	};
	Sprite KursorSprite; 
	Texture KursorTexture;
	Sprite MenuSprite;
	Texture MenuTexture;
	Text Money;
	bool in_shop = false;
	bool buying = false;
	Font font;
	int pozycja_y = 0;
public:
	Sprite getSprite();
	void move(int kierunek);
	void ustaw_pieniadze(int pieniadze, int x, int y);
	virtual void ustaw_pozycje(int x, int y, string nazwa);
	int getPozycja();
	void im_buying();
	void im_in_shop();
	bool czy_kupuje();
	void draw(RenderWindow &m_Window);
	Menu(string nazwa);
	Menu();
	~Menu();
};
