#pragma once
#include "Przedmiot.h"

using namespace std;
using namespace sf;

class Potion :
	public Przedmiot
{
	int ulecz_za;
public:
	Potion(int ile);
	~Potion();

	int za_ile_leczy();
	int lap()
	{
		return 0;
	};
};

