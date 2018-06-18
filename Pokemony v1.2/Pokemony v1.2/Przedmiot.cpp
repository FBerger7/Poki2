#include "Przedmiot.h"


int Przedmiot::getLiczba()
{
	return liczba;
}

void Przedmiot::setLiczba(int i)
{
	liczba += i;
	Ilosc.setString("x" + to_string(liczba));
}

string Przedmiot::getID()
{
	return id;
}

void Przedmiot::setPosition(float x, float y)
{
	PrzedmiotSprite.setPosition(x, y);
	Nazwa.setPosition(x + 30 , y);
	Ilosc.setPosition(x + 400, y);
}



Sprite Przedmiot::getSprite()
{
	return PrzedmiotSprite;
}

Text Przedmiot::getNazwa()
{
	return Nazwa;
}

Text Przedmiot::getIlosc()
{
	return Ilosc;
}

