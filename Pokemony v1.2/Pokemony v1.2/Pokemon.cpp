#include "Pokemon.h"

void Pokemon::zrob_sojusznik()
{
	sojusznik = true;
}

void Pokemon::scale_sprite()
{
	PokemonSprite.scale(4.f, 4.f);
}

void Pokemon::ustaw_Nazwe()
{
	font.loadFromFile("arial.ttf");
	Nazwa.setFont(font);
	if (sojusznik)
	{
		Nazwa.setPosition(520.f, 306.f);
		Nazwa.setCharacterSize(17);
	}
	else
	{
		Nazwa.setPosition(38.f, 35.f);
		Nazwa.setCharacterSize(16);
	}
	Nazwa.setStyle(Text::Bold);
	Nazwa.setFillColor(Color::Black);
}

void Pokemon::ustaw_LVL()
{
	font.loadFromFile("arial.ttf");
	Level.setFont(font);
	if (sojusznik)
	{
		Level.setPosition(728.f, 302.f);
		Level.setCharacterSize(19);
	}
	else
	{
		Level.setPosition(246.f, 31.f);
		Level.setCharacterSize(18);
	}
	Level.setStyle(Text::Bold);
	Level.setFillColor(Color::Black);
}


Text Pokemon::getNazwa()
{
	return Nazwa;
}

Text Pokemon::getLevel()
{
	return Level;
}

float Pokemon::getATK()
{
	return ATK;
}

float Pokemon::getDEF()
{
	return DEF;
}

float Pokemon::getSPD()
{
	return SPD;
}

float Pokemon::getC_HP()
{
	return C_HP;
}

float Pokemon::getMAX_HP()
{
	return MAX_HP;
}

float Pokemon::getC_EXP()
{
	return C_EXP;
}

float Pokemon::getMAX_EXP()
{
	return MAX_EXP;
}

Sprite Pokemon::getSprite()
{
	return PokemonSprite;
}

int Pokemon::getLVL()
{
	return LVL;
}