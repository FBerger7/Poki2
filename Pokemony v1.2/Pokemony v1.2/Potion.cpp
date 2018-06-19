#include "Potion.h"



Potion::Potion(int ile)
{
	id = "potion";
	liczba = ile;
	ulecz_za = 20;

	font.loadFromFile("arial.ttf");
	Nazwa.setFont(font);
	Nazwa.setString("Potion");
	Nazwa.setCharacterSize(17);
	Nazwa.setStyle(Text::Bold);
	Nazwa.setFillColor(Color::Black);
	
	Ilosc.setFont(font);
	Ilosc.setString("x" + to_string(liczba));
	Ilosc.setCharacterSize(17);
	Ilosc.setStyle(Text::Bold);
	Ilosc.setFillColor(Color::Black);

	PrzedmiotTexture.loadFromFile("Potion.png");
	PrzedmiotSprite.setTexture(PrzedmiotTexture);


}


Potion::~Potion()
{
}

int Potion::lap()
{
	return ulecz_za;
};
