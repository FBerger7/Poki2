#include "Poliwrath.h"

#define MAX_EXP_UP 50
#define MAX_HP_UP 5
#define ATK_UP 5
#define DEF_UP 6
#define SPD_UP 3


void Poliwrath::ustaw_statystyki(int lvl)
{
	C_EXP = 0;
	MAX_EXP = 100 + (lvl * MAX_EXP_UP);
	C_HP = MAX_HP = 10 + (lvl * MAX_HP_UP);
	ATK = 5 + (lvl * ATK_UP);
	DEF = 8 + (lvl * DEF_UP);
	SPD = 5 + (lvl * SPD_UP);
	TYP = Water;
}

Poliwrath::Poliwrath(int lvl, bool s)
{
	sojusznik = s;
	LVL = lvl;
	
	Nazwa.setString("Poliwrath");
	ustaw_Nazwe();

	Level.setString(to_string(lvl));
	ustaw_LVL();

	ustaw_statystyki(lvl);
	setSprite();

	dodaj_atak(new Cut());
	dodaj_atak(new Cut());
	dodaj_atak(new Cut());
	dodaj_atak(new Cut());

	if (s)
		for (int i = 0; i < lista_atakow.size(); i++)
			lista_atakow[i]->ustaw_Nazwe();
}

Poliwrath::~Poliwrath()
{
}

void Poliwrath::setSprite()
{
	if (sojusznik == true)
	{
		PokemonTexture.loadFromFile("Pokemon_back.png");
		IntRect wybor_pokemona(161, 396, 50, 50);
		PokemonSprite.setTexture(PokemonTexture);
		PokemonSprite.setTextureRect(wybor_pokemona);
		PokemonSprite.setPosition(85, 195);
	}

	else
	{
		PokemonTexture.loadFromFile("Pokemon_front.png");
		IntRect wybor_pokemona(328, 472, 56, 56);
		PokemonSprite.setTexture(PokemonTexture);
		PokemonSprite.setTextureRect(wybor_pokemona);
		PokemonSprite.setPosition(500, 37);
	}
	scale_sprite();
}

void Poliwrath::lvl_up() //skalowanie pokemonow napotkanych w krzakach
{
	MAX_HP += MAX_HP_UP;
	ATK += ATK_UP;
	DEF += DEF_UP;
	SPD += SPD_UP;
	MAX_EXP += LVL * MAX_EXP_UP;
}