#include "Stelfozaur.h"

#define MAX_EXP_UP 70
#define MAX_HP_UP 6
#define ATK_UP 5
#define DEF_UP 5
#define SPD_UP 4

Stelfozaur::Stelfozaur(int lvl, bool s)
{
	LVL = lvl;
	sojusznik = s;

	Nazwa.setString("Stelfozaur");
	ustaw_Nazwe();

	Level.setString(to_string(lvl));
	ustaw_LVL();

	C_EXP = 0;
	MAX_EXP = 100 + (lvl * MAX_EXP_UP);
	C_HP = MAX_HP = 15 + (lvl * MAX_HP_UP);
	ATK = 4 + (lvl * ATK_UP);
	DEF = 10 + (lvl * DEF_UP);
	SPD = 4 + (lvl * SPD_UP);
	TYP = Electric;
	setSprite();
}


Stelfozaur::~Stelfozaur()
{
}

void Stelfozaur::setSprite()
{
	if (sojusznik == true)
	{
		PokemonTexture.loadFromFile("Pokemon_back.png");
		IntRect wybor_pokemona(159, 848, 50, 50);
		PokemonSprite.setTexture(PokemonTexture);
		PokemonSprite.setTextureRect(wybor_pokemona);
		PokemonSprite.setPosition(85, 195);
	}

	else
	{
		PokemonTexture.loadFromFile("Pokemon_front.png");
		IntRect wybor_pokemona(521, 985, 56, 56);
		PokemonSprite.setTexture(PokemonTexture);
		PokemonSprite.setTextureRect(wybor_pokemona);
		PokemonSprite.setPosition(500, 37);
	}
	scale_sprite();
}

void Stelfozaur::lvl_up()
{
	MAX_HP += MAX_HP_UP;
	ATK += ATK_UP;
	DEF += DEF_UP;
	SPD += SPD_UP;
	MAX_EXP += LVL * MAX_EXP_UP;
}
