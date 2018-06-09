#pragma once

#include <SFML/Graphics.hpp>
#include "Actors.h"
#include "Sceny.h"
#include <cstdlib>
#include<ctime>
#include "Mapa.h"
#include "Pokemon.h"
#include "Okno_pokemon.h"

using namespace sf;


class Engine
{
private:
	//RenderWindow
	RenderWindow m_Window;
	
	View view_e;
	View view_b;
	View view_budynku;
	View view_pokemon;

	// Tu bedzie gracz
	Gracz ethan;

	map<string, Actors*> Lista_aktorow;
	map<string, Actors*>::iterator it;
	// Tryb gry
	bool walka = false;
	bool is_in_gym = false;
	bool menu_pokemon = false;
	int RANDOM_NUMBER = 100;

	//MAPA
	Mapa *map1;
	Mapa *GYM_MAP;
	
	Okno_walki *pojedynek;

	Okno_eksploracji *mapa;
	Okno_eksploracji *GYM;

	Okno_pokemon *pokemon_window;

	// Funkcje prywatne do uzytku wewnetrznego
	void input(); 
	void update();
	void draw();

public:
	Engine();
	bool czy_jest_walka();
	void start();

};