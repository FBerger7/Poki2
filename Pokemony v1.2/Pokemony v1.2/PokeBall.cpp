#include "PokeBall.h"



PokeBall::PokeBall(int ile)
{
	id = "pokeball";
	liczba = ile;
	szansa_na_zlapanie = 5.f;

	font.loadFromFile("arial.ttf");
	Nazwa.setFont(font);
	Nazwa.setString("PokeBall");
	Nazwa.setStyle(Text::Bold);
	Nazwa.setFillColor(Color::Black);
	Nazwa.setCharacterSize(17);

	Ilosc.setFont(font);
	Ilosc.setString("x" + to_string(liczba));
	Ilosc.setCharacterSize(17);
	Ilosc.setStyle(Text::Bold);
	Ilosc.setFillColor(Color::Black);

	PrzedmiotTexture.loadFromFile("PokeBall.png");
	PrzedmiotSprite.setTexture(PrzedmiotTexture);
}


PokeBall::~PokeBall()
{
}

int PokeBall::lap()
{
	return szansa_na_zlapanie;
}
