#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

using namespace std;
using namespace sf;

class Przedmiot
{
protected:
	Font font;
	Text Nazwa;
	Text Ilosc;
	Texture PrzedmiotTexture;
	Sprite PrzedmiotSprite;
	int liczba;
	string id;
public:
	int getLiczba();
	void setLiczba(int i);
	string getID();
	void setPosition(float x, float y);
//	void update(Gracz &ethan);
	Sprite getSprite();
	Text getNazwa();
	Text getIlosc();
	void zurzyj();

	virtual int lap() = 0;
};

