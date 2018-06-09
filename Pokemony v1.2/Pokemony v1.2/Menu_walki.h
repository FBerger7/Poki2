#pragma once
#include <SFML/Graphics.hpp>
#include "Pokemon.h"

using namespace std;
using namespace sf;

	typedef enum Akcja {
		Menu,
		Walka,
		Lista_pokemon
	};

class Menu_walki
{
	enum Direction {
		RIGHT,
		LEFT,
		DOWN,
		UP,
		EXIT,
		BACK};
	Sprite KursorSprite; //battle background
	Texture KursorTexture;
	int indeks;
	Akcja rodzaj_menu;
	bool wyjdz_z_walki;

public:
	Sprite getSprite();
	Akcja getRodzaj();
	int getIndeks();
	bool getWyjdz_z_walki();

	void move(int kierunek);
	void akcja();
	void wybierz_atak(Pokemon *pokemon, int kierunek);

	Menu_walki();
	~Menu_walki();
};

