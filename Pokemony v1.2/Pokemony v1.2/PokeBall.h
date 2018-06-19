#pragma once
#include "Przedmiot.h"

using namespace std;
using namespace sf;

class PokeBall :
	public Przedmiot
{
	float szansa_na_zlapanie;
public:
	PokeBall(int ile);
	~PokeBall();

	int lap();
};

