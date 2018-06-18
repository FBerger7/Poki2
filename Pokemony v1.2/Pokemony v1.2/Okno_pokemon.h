#pragma once
#include "Sceny.h"
#include <SFML/Graphics.hpp>
#include "Biblioteka_Pokemonow.h"
#include "Actors.h"

using namespace std;
using namespace sf;

class Okno_pokemon :
	public Scena_abstrakcyjna
{
	Sprite KursorSprite; //battle background
	Texture KursorTexture;

	RectangleShape zaznaczenie;
	int zaznaczenie_bool;

	int indeks;
	int liczba_pokemonow_ethana;
public:
	Okno_pokemon(RenderWindow &m_Window);
	~Okno_pokemon();

	void move_kursor(Direction y);
	void create(RenderWindow &m_Window);
	void draw(RenderWindow &m_Window,Gracz ethan);
	int swap();
	void zaznacz();

	void swap(Gracz &ethan);

	void setZaznaczenie();
	int getZaznaczenie();
};

