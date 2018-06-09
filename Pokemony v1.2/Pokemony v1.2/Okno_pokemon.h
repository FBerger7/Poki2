#pragma once
#include "Sceny.h"
#include <SFML/Graphics.hpp>
#include "Biblioteka_Pokemonow.h"

using namespace std;
using namespace sf;

class Okno_pokemon :
	public Scena_abstrakcyjna
{
	vector<RectangleShape> Pokemon_texture;
public:
	Okno_pokemon();
	~Okno_pokemon();

	void create(RenderWindow &m_Window);
	void draw(RenderWindow &m_Window);
};

