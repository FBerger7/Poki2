#include "Menu.h"



Sprite Menu::getSprite()
{
	return KursorSprite;
}

void Menu::move(int kierunek)
{
	int x = 0;
	if (buying) x = 1;
	else if (in_shop) x = 2;
	else x = 3;
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
		if (pozycja_y != x)
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
	if (in_shop)
	{
		Money.setPosition(x + 40, y - 67);
		Money.setCharacterSize(8);
		Money.setString(to_string(pieniadze));
	}
	else
	{	
		Money.setPosition(x + 60, y - 39);
		Money.setCharacterSize(8);
		Money.setString(to_string(pieniadze));
	}

}

void Menu::draw(RenderWindow &m_Window)
{
	m_Window.draw(MenuSprite);
	m_Window.draw(KursorSprite);
	if (!buying)
	m_Window.draw(Money);
};

void Menu::ustaw_pozycje(int x, int y, string nazwa)
{
	if (nazwa == "MENU")
	{
		x += 42;
		y -= 70;
		MenuSprite.setPosition(x, y);
		KursorSprite.setPosition(x+6, y+52);
	}
	else if (nazwa == "SHOP")
	{
		x -= 65;
		y -= 75;
		MenuSprite.setPosition(x, y);
		KursorSprite.setPosition(x + 6, y +7);
	}
	else if (nazwa == "SHOP2")
	{
		x -= 50;
		y -= 57;
		MenuSprite.setPosition(x, y);
		KursorSprite.setPosition(x + 8, y + 14);
	}
}

int Menu::getPozycja()
{
	return pozycja_y;
}

void Menu::im_buying()
{
	this->buying = true;
}

void Menu::im_in_shop()
{
	this->in_shop = true;
}

bool Menu::czy_kupuje()
{
	return buying;
}


Menu::Menu(string nazwa)
{
	KursorTexture.loadFromFile("Kursor2.png");
	KursorSprite.setTexture(KursorTexture);
	if (nazwa == "MENU")
		MenuTexture.loadFromFile("Menu.png");
	else if (nazwa == "SHOP")
		MenuTexture.loadFromFile("Sklep_First.png");
	else if(nazwa == "SHOP2")
		MenuTexture.loadFromFile("Sklep_Second.png");
	MenuSprite.setTexture(MenuTexture);
	if (nazwa == "SHOP" || nazwa == "SHOP2")
		MenuSprite.setScale(0.25, 0.25);
	this->pozycja_y = 0;
}

Menu::Menu()
{
}

Menu::~Menu()
{
}
