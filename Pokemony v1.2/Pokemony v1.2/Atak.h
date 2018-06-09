#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class Atak
{
protected:
	float Sila;
	int Indeks; //numer w mapie

	Font font;
	Text Nazwa;

public:
	float getSila();
	Text getNazwa();

	void setIndeks(int i);
	void ustaw_Nazwe();

	Atak();
	~Atak();
};

