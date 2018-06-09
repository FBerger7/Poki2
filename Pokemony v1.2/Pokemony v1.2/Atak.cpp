#include "Atak.h"



float Atak::getSila()
{
	return Sila;
}

Text Atak::getNazwa()
{
	return Nazwa;
}

void Atak::setIndeks(int i)
{
	Indeks = i;
}

void Atak::ustaw_Nazwe()
{
	font.loadFromFile("arial.ttf");
	Nazwa.setFont(font);

	Nazwa.setStyle(Text::Bold);
	Nazwa.setFillColor(Color::Black);
	Nazwa.setCharacterSize(25);

	switch (Indeks)
	{
	case 1:
		Nazwa.setPosition(48.f, 439.f);
		break;
	case 2:
		Nazwa.setPosition(188.f, 439.f);
		break;

	case 3:
		Nazwa.setPosition(48.f, 512.f);
		break;

	case 4:
		Nazwa.setPosition(188.f, 512.f);
		break;
	}

}

Atak::Atak()
{
}


Atak::~Atak()
{
}
