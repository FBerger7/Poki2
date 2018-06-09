#include "Menu.h"



Sprite Menu::getSprite()
{
	return KursorSprite;
}

void Menu::move(int kierunek)
{
	switch (kierunek)
	{
	case UP:
		if (pozycja_y != 0)
		{
			KursorSprite.move(0.f, -70.f);
			pozycja_y = 0;
		}
		break;
	case DOWN:
		if (pozycja_y != 1)
		{
			KursorSprite.move(0.f, 70.f);
			pozycja_y = 1;
		}
		break;
	}
}

void Menu::draw(RenderWindow &m_Window)
{
	m_Window.draw(MenuSprite);
};

void Menu::ustaw_pozycje(int x, int y)
{
	x += 42;
	y -= 70;
	MenuSprite.setPosition(x, y);
}

Menu::Menu()
{
	KursorTexture.loadFromFile("Kursor.png");
	KursorSprite.setTexture(KursorTexture);
	KursorSprite.setPosition(368.f, 457.f);
	MenuTexture.loadFromFile("Menu.png");
	MenuSprite.setTexture(MenuTexture);
	pozycja_x = 0;
	pozycja_y = 0;
}

Menu::~Menu()
{
}
