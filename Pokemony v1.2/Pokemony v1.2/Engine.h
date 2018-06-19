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
#include "Okno_pokemon.h"
#include "Okno_przedmiotow.h"
#include "Menu.h"
#include "BaseException.h"

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
	View view_plecak;

	// Tu bedzie gracz
	Gracz ethan;
	NPC* gym_leader;

	map<string, Actors*> Lista_aktorow;
	map<string, Actors*>::iterator it;
	// Tryb gry
	bool walka = false;
	bool walka_zNPC = false;
	bool is_in_gym = false;
	bool is_in_PokeCenter = false;
	bool is_in_PokeMart = false;
	bool menu_is_open = false;
	bool menu_pokemon = false;
	bool menu_plecak = false;
	bool shop_is_open = false;
	bool buying_is_open = false;
	int RANDOM_NUMBER = 100;

	int walka_z_bossem = 1;

	//MUZYKA
	Music gym_music;
	Music cerulean_music;
	Music vs_poke_battle_music;
	Music route_music;
	Music poke_center_music;

	//MENU
	Menu*opcje;
	Menu*shop;
	Menu*shop_buy;

	//MAPA
	Mapa *map1;
	Mapa *GYM_MAP;
	
	Okno_walki *pojedynek;

	Okno_eksploracji *mapa;
	Okno_eksploracji *GYM;
	Okno_eksploracji *PokeCenter;
	Okno_eksploracji *PokeMart;

	Okno_pokemon *pokemon_window;

	Okno_przedmiotow *plecak_window;

	// Funkcje prywatne do uzytku wewnetrznego

public:
	void input(); 
	void update();
	void draw();
	Engine();
	bool czy_jest_walka();
	void start();
	~Engine();
};