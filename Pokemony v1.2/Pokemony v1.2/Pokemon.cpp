#include "Pokemon.h"

void Pokemon::zrob_sojusznik()
{
	sojusznik = true;
}

void Pokemon::scale_sprite()
{
	PokemonSprite.scale(4.f, 4.f);
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