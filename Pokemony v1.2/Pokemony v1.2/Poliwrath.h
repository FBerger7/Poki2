#pragma once
#include "Pokemon.h"

using namespace std;
using namespace sf;

class Poliwrath 
	:public Pokemon
{	
public:	
	Poliwrath(int lvl,bool s);
	~Poliwrath();

	void setSprite();
	void lvl_up();
};

