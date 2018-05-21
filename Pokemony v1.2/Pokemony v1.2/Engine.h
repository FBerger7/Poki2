#pragma once

#include <SFML/Graphics.hpp>
#include "Actors.h"
#include "Mapa.h"


using namespace sf;



class Engine
{
private:
	//RenderWindow
	RenderWindow m_Window;
	View view;
	// Tlo
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//MAPA
	Mapa *map1;

	// Tu bedzie gracz
	Gracz ethan;

	// Funkcje prywatne do uzytku wewnetrznego
	void input();
	void update();
	void draw();

public:
	Engine();

	void start();

};