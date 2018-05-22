#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum Type {Normal, Fire, Water, Air, Electric, Earth};

class Pokemon
{
	Texture PokemonTexture;
	bool sojusznik;
	float ATK;
	float DEF;
	float SPD;
	Type TYP;

	
public:
	float C_EXP;
	float MAX_EXP;
	float C_HP;
	float MAX_HP;
	Sprite PokemonSprite; 
	Pokemon();
	void scale(int level, bool czy_sojusznik);
	~Pokemon();
};

