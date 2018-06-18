#include "Menu_walki.h"


Menu_walki::Menu_walki()
{
	KursorTexture.loadFromFile("Kursor.png");
	KursorSprite.setTexture(KursorTexture);
	KursorSprite.setPosition(368.f, 457.f);
	indeks = 1;
	wyjdz_z_walki = false;
	rodzaj_menu= Menu_walka;
}



Menu_walki::~Menu_walki()
{
}

Sprite Menu_walki::getSprite()
{
	return KursorSprite;
}

Akcja Menu_walki::getRodzaj()
{
	return rodzaj_menu;
}

int Menu_walki::getIndeks()
{
	return indeks;
}

bool Menu_walki::getWyjdz_z_walki()
{
	return wyjdz_z_walki;
}

void Menu_walki::move(int kierunek)
{
	switch (kierunek)
	{
	case UP:
		if (indeks > 2)
		{
			if (rodzaj_menu == Menu_walka)
				KursorSprite.move(0.f, -70.f);
			else if (rodzaj_menu == Walka)
				KursorSprite.move(0.f, -73.f);
			indeks -= 2;
		}
		break;
	case DOWN:
		if (indeks < 3)
		{
			if (rodzaj_menu == Menu_walka)
				KursorSprite.move(0.f, 70.f);
			else if (rodzaj_menu == Walka)
				KursorSprite.move(0.f, 73.f);
			indeks += 2;
		}
		break;
	case LEFT:
		if (indeks % 2 == 0)
		{
			if (rodzaj_menu == Menu_walka)
				KursorSprite.move(-240.f, 0.f);
			else if (rodzaj_menu == Walka)
				KursorSprite.move(-140.f, 0.f);
			indeks -= 1;
		}
		break;
	case RIGHT:
		if (indeks % 2 == 1)
		{
			if (rodzaj_menu == Menu_walka)
				KursorSprite.move(240.f, 0.f);
			else if (rodzaj_menu == Walka)
				KursorSprite.move(140.f, 0.f);
			indeks += 1;
		}
		break;
	case BACK:
		switch (rodzaj_menu)
		{
		case Walka:
			indeks = 1;
			KursorSprite.setPosition(368.f, 457.f);
			KursorSprite.scale(2.f, 2.f);
			break;
		case Lista_pokemon:
			indeks = 2;
			KursorSprite.setPosition(608.f, 457.f);
			break;
		case Lista_przedmiotow:
			indeks = 3;
			KursorSprite.setPosition(368.f, 527.f);
		}
		rodzaj_menu = Menu_walka;
		break;
	case EXIT:
		KursorSprite.setPosition(608.f, 527.f);
		indeks = 4;

		break;
	}
}

void Menu_walki::akcja()
{
	switch (indeks)
	{
	case 1:
		if (rodzaj_menu == Menu_walka)
		{
			rodzaj_menu = Walka;
			KursorSprite.setPosition(32.f, 443.f);
			KursorSprite.scale(0.5f,0.5f);
		}
		break;
	case 2:
		rodzaj_menu = Lista_pokemon;
		break;
	case 3:
		rodzaj_menu = Lista_przedmiotow;
		break;
	case 4:
		wyjdz_z_walki = true;
		break;
	}
}

void Menu_walki::wybierz_atak(Pokemon * pokemon, int kierunek)
{
}

