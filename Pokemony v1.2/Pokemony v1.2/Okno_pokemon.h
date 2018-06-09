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
public:
	Okno_pokemon(RenderWindow &m_Window);
	~Okno_pokemon();

	void create(RenderWindow &m_Window);
	void draw(RenderWindow &m_Window,Gracz ethan);
};

