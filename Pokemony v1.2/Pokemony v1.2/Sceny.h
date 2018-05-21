#pragma once

//#include"TextureManager.hpp"
#include<string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class Scena_abstrakcyjna :
	public Sprite
{
public:
	Scena_abstrakcyjna();
	virtual void create() = 0;
	~Scena_abstrakcyjna();
};
