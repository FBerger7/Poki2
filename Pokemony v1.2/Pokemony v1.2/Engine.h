#pragma once

#include <SFML/Graphics.hpp>
#include "Actors.h"
#include "Sceny.h"

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

	Okno_eksploracji mapa;
	Okno_walki pojedynek;

	// Funkcje prywatne do uzytku wewnetrznego
	void input();
	void update();
	void draw();

public:
	Engine();

	void start();

};