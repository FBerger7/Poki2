#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include "Pokemon.h"
#include "Biblioteka_pokemonow.h"


using namespace std;
using namespace sf;

enum Direction {
	RIGHT,
	LEFT,
	DOWN,
	UP,
	EXIT,
	BACK
};

class Actors :
	public Drawable
{
public:
	Actors();
	void draw(RenderTarget & target, RenderStates state) const = 0;
	~Actors();
};

class Gracz :
	public Actors
{
	RectangleShape osoba;
	float x = 0, y = 0;
	int xm = 0, ym = 0;
	vector<Pokemon*>lista_pokemonow;
public:
	Gracz();
	~Gracz();
	Texture ethan_tex;
	map<string, Gracz> Lista_aktorow;
	map<string, Gracz>::iterator it;
	Gracz(float Tx, float Ty);
	void draw(RenderTarget & target, RenderStates state) const;
	//Gracz(int x, int y);
	void move(Direction D);
	RectangleShape getSprite();
	IntRect ustaw_kierunek_tekstury(Direction D);
	void set_xm(int _x);
	void set_ym(int _y);
	int get_xm();
	int get_ym();
	void setSprite(Texture &imgpath);
	void ustaw_pozycje(float Tx, float Ty);
	float getX();
	float getY();

	void dodaj_pokemona(Pokemon* pok);
	Pokemon* getPokemon(int indeks);
	vector<Pokemon*> getlista_pok();
};



class NPC :
	public Actors
{
	NPC();

	~NPC();
};
