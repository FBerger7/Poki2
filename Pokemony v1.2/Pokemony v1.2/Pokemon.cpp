#include "Pokemon.h"



Pokemon::Pokemon()
{
	C_EXP = 0;
	MAX_EXP = 100;
	C_HP = MAX_HP = 10;
	ATK = 5;
	DEF = 8;
	SPD = 5;
	TYP = Normal;
}

void Pokemon::scale(int level,bool czy_sojusznik)
{
	sojusznik = czy_sojusznik;
	C_HP = 10;
	MAX_HP += 3 * level;
	ATK += 4 * level;
	DEF += 3 * level;
	SPD += 2 * level;
	if (czy_sojusznik == true)
	{
		MAX_EXP += level*level * 50;
		IntRect wybor_pokemona(161, 396, 50, 50);
		PokemonTexture.loadFromFile("Pokemon_back.png");
		PokemonSprite.setTexture(PokemonTexture);
		PokemonSprite.setTextureRect(wybor_pokemona);
		PokemonSprite.setPosition(145, 225);
	}
	
	else
	{
		IntRect wybor_pokemona(328, 472, 56, 56);
		PokemonTexture.loadFromFile("Pokemon_front.png");
		PokemonSprite.setTexture(PokemonTexture);
		PokemonSprite.setTextureRect(wybor_pokemona);
		PokemonSprite.setPosition(470, 57);
	}
	PokemonSprite.scale(3.f, 3.f);
}


Pokemon::~Pokemon()
{
}
