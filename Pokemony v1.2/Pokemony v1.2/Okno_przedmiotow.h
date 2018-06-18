#pragma once
#include "Sceny.h"

class Okno_przedmiotow :
	public Scena_abstrakcyjna

{
	Sprite KursorSprite; //battle background
	Texture KursorTexture;

	int indeks;
public:
	Okno_przedmiotow();
	~Okno_przedmiotow();

	void draw(RenderWindow & m_Window, Gracz ethan);
	void move_kursor(Direction y, Gracz ethan);
	void zresetuj_kursor();
	int getIndeks();
};

