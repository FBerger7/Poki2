#include "Menu_walki.h"



Sprite Menu_walki::getSprite()
{
	return KursorSprite;
}

void Menu_walki::move(int kierunek)
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
	case LEFT:
		if (pozycja_x != 0)
		{
			KursorSprite.move(-240.f, 0.f);
			pozycja_x = 0;
		}
		break;
	case RIGHT:
		if (pozycja_x != 1)
		{
			KursorSprite.move(240.f, 0.f);
			pozycja_x = 1;
		}
		break;
	}
}

Menu_walki::Menu_walki()
{
	KursorTexture.loadFromFile("Kursor.png");
	KursorSprite.setTexture(KursorTexture);
	KursorSprite.setPosition(368.f, 457.f);
	pozycja_x = 0;
	pozycja_y = 0;
}



Menu_walki::~Menu_walki()
{
}
