#pragma once
#include "Pokemon.h"

using namespace std;
using namespace sf;

class Stelfozaur :
	public Pokemon
{
	void ustaw_statystyki(int lvl);
public:
	Stelfozaur(int lvl, bool s);
	~Stelfozaur();

	void setSprite();
	void lvl_up();
};

