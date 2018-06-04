#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Actors.h"
#include "Sceny.h"
#include <cstdlib>
#include<ctime>
#include<thread>
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
	View view_budynku;

	// Tu bedzie gracz
	Gracz ethan;
	// Tryb gry
	bool walka = false;
	bool is_in_gym = false;
	bool is_in_PokeCenter = false;
	int RANDOM_NUMBER = 100;

	//MUZYKA
	Music gym_music;
	Music cerulean_music;
	Music vs_poke_battle_music;
	Music route_music;

	//MAPA
	Mapa *map1;
	Mapa *GYM_MAP;
	
	Okno_walki *pojedynek;
	Okno_eksploracji *mapa;
	Okno_eksploracji *GYM;
	Okno_eksploracji *PokeCenter;
	

public:
	Engine();
	void input(); 
	void update();
	void draw();
	bool czy_jest_walka();
	void start();

};