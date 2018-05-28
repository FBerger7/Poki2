#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum Type { Normal, Fire, Water, Air, Electric, Earth };

class Pokemon
{
protected:
	bool sojusznik;
	float ATK;
	float DEF;
	float SPD;
	Type TYP;
	float C_EXP;
	float MAX_EXP;
	float C_HP;
	float MAX_HP;
	int LVL;
	Texture PokemonTexture;
	Sprite PokemonSprite;

	Font font;
	Text Nazwa;
	Text Level;

public:

	// Pobieranie danych pokemona    --- Metody wspolne
	Text getNazwa();
	Text getLevel();
	float getATK();
	float getDEF();
	float getSPD();
	float getC_HP();
	float getMAX_HP();
	float getC_EXP();
	float getMAX_EXP();
	Sprite getSprite();
	int getLVL();
	//-------------------------------------------------


	void zrob_sojusznik();
	void scale_sprite();

	void ustaw_Nazwe();
	void ustaw_LVL();
	//----------------------------


	// Metody wirtualne
	virtual void setSprite()=0;
	virtual void lvl_up()=0;

};

