#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum Type {Normal, Fire, Water, Air, Electric, Earth};

class Pokemon
{
	float MAX_HP;
	float ATK;
	float DEF;
	float SPD;
	Type TYP;

	float C_HP;
	
public:
	Pokemon();
	~Pokemon();
};

