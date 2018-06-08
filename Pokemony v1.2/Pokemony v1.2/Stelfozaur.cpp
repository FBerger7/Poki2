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

	ustaw_statystyki(lvl);

	setSprite();

	dodaj_atak(new Cut());

	if (s)
	{
		for (auto i = lista_atakow.front(); i < lista_atakow.back(); i++)
			i->ustaw_Nazwe();
		ustaw_HP_txt();
	}
}


Stelfozaur::~Stelfozaur()
{

}

void Stelfozaur::ustaw_statystyki(int lvl)
{
	C_EXP = 0;
	MAX_EXP = 100 + (lvl * MAX_EXP_UP);
	C_HP = MAX_HP = 15 + (lvl * MAX_HP_UP);
	ATK = 4 + (lvl * ATK_UP);
	DEF = 10 + (lvl * DEF_UP);
	SPD = 4 + (lvl * SPD_UP);
	TYP = Electric;

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
	LVL++;
	MAX_HP += MAX_HP_UP;
	C_HP += MAX_HP_UP;
	ATK += ATK_UP;
	DEF += DEF_UP;
	SPD += SPD_UP;
	MAX_EXP += LVL * MAX_EXP_UP;
	Level.setString(to_string(LVL));

	C_HP_txt.setString(to_string(C_HP));
	MAX_HP_txt.setString(to_string(MAX_HP));
}
