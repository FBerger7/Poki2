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
			KursorSprite.move(0.f, -16.f);
			pozycja_y -= 1;
		}
		break;
	case DOWN:
		if (pozycja_y != 3)
		{
			KursorSprite.move(0.f, 16.f);
			pozycja_y += 1;
		}
		break;
	}
}

void Menu::ustaw_pieniadze(int pieniadze, int x, int y)
{
	font.loadFromFile("arial.ttf");
	Money.setFont(font);
	Money.setFillColor(Color::Black);
	Money.setPosition(x + 60, y - 39);
	Money.setCharacterSize(8);
	Money.setString(to_string(pieniadze));

}

void Menu::draw(RenderWindow &m_Window)
{
	m_Window.draw(MenuSprite);
	m_Window.draw(KursorSprite);
	m_Window.draw(Money);
};

void Menu::ustaw_pozycje(int x, int y)
{
	x += 42;
	y -= 70;
	MenuSprite.setPosition(x, y);
	KursorSprite.setPosition(x+6, y+52);
}

int Menu::getPozycja()
{
	return pozycja_y;
}

Menu::Menu()
{
	KursorTexture.loadFromFile("Kursor2.png");
	KursorSprite.setTexture(KursorTexture);
	MenuTexture.loadFromFile("Menu.png");
	MenuSprite.setTexture(MenuTexture);
	this->pozycja_y = 0;
}

Menu::~Menu()
{
}
