#pragma once
#include "Pokemon.h"

using namespace std;
using namespace sf;

class Stelfozaur :
	public Pokemon
{
public:
	Stelfozaur(int lvl, bool s);
	~Stelfozaur();

	void setSprite();
	void lvl_up();
};

