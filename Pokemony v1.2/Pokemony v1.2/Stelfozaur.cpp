#include "Stelfozaur.h"

#define MAX_EXP_UP 70

#define MAX_HP_UP 6
#define ATK_UP 4
#define DEF_UP 3
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
	dodaj_atak(new Punch());

	if (s)
	{
		for (int i = 0; i < lista_atakow.size(); i++)
			lista_atakow[i]->ustaw_Nazwe();
		ustaw_HP_txt();
	}
}


Stelfozaur::~Stelfozaur()
{

}

void Stelfozaur::ustaw_statystyki(int lvl)
{
	C_EXP = 0;
	MAX_EXP = 100 + (lvl * lvl * 0.1 * MAX_EXP_UP);
	C_HP = MAX_HP = 15 + (lvl * MAX_HP_UP);
	ATK = 2 + (lvl * ATK_UP);
	DEF = 8 + (lvl * DEF_UP);
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

		PokemonTexture_menu.loadFromFile("Pokemon_front.png");
		IntRect wybor_pokemona2(521, 985, 56, 56);
		PokemonSprite_menu.setTexture(PokemonTexture_menu);
		PokemonSprite_menu.setTextureRect(wybor_pokemona2);
		PokemonSprite_menu.scale(1.7f, 1.7f);
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

	int i = (int)floor(C_HP + 0.5);
	C_HP_txt.setString(to_string(i));
	i = (int)floor(MAX_HP + 0.5);
	MAX_HP_txt.setString(to_string(i));
}
