#pragma once
#include <SFML/Graphics.hpp>
#include "Biblioteka_atakow.h"
#include <vector>

using namespace std;
using namespace sf;


class Pokemon
{
protected:
	enum Type { Normal, Fire, Water, Air, Electric, Earth };
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

	Texture PokemonTexture_menu;
	Sprite PokemonSprite_menu;

	Font font;
	Text Nazwa;
	Text Level;
	Text C_HP_txt;
	Text MAX_HP_txt;

	virtual void ustaw_statystyki(int lvl)=0;

public:
	vector <Atak*> lista_atakow;

	// Pobieranie danych pokemona    --- Metody wspolne
	Text getNazwa();
	Text getLevel();
	Text getC_HP_txt();
	Text getMAX_HP_txt();

	float getATK();
	float getDEF();
	float getSPD();

	float getC_HP();
	float getMAX_HP();

	float getC_EXP();
	float getMAX_EXP();

	Sprite getSprite();

	Sprite getSprite_menu(int i);
	int getLVL();
	//-------------------------------------------------
	void setC_HP(float damage);
	void setC_EXP(float exp);

	void zrob_sojusznik();
	void scale_sprite();

	void ustaw_Nazwe();
	void ustaw_LVL();
	void ustaw_HP_txt();

	void setHP_txt();
	//----------------------------
	float stosunek_hp();
	void dodaj_atak(Atak* nowy_atak);
	void heal();
	void heal(float hp);

	// Metody wirtualne
	virtual void setSprite()=0;
	virtual void lvl_up()=0;

};

