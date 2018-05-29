#pragma once

#include <SFML/Graphics.hpp>
#include "Actors.h"
#include "Sceny.h"
#include <cstdlib>
#include<ctime>
#include "Mapa.h"
#include "Pokemon.h"
using namespace sf;



class Engine
{
private:
	//RenderWindow
	RenderWindow m_Window;
	
	View view_e;
	View view_b;

	// Tu bedzie gracz
	Gracz ethan;
	// Tryb gry
	bool walka = false;
	bool is_in_gym = false;
	int RANDOM_NUMBER = 100;

	//MAPA
	Mapa *map1;
	Mapa *GYM_MAP;
	
	Okno_eksploracji mapa;
	Okno_eksploracji *GYM;
	Okno_walki pojedynek;
	
	// Funkcje prywatne do uzytku wewnetrznego
	void input(); 
	void update();
	void draw();

public:
	Engine();
	bool czy_jest_walka();
	void start();

};