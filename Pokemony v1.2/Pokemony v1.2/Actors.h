#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include "Pokemon.h"
#include "Biblioteka_pokemonow.h"
#include "Przedmiot.h"
#include "Lista_przedmiotow.h"


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
protected:
	float x = 0, y = 0;
	int xm = 0, ym = 0;
	RectangleShape osoba;
public:
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
	RectangleShape getosoba();

	Actors();
	~Actors();
};

class Gracz :
	public Actors
{
int piniondze;
public:
	map<string,Przedmiot*>plecak;
	map<string,Przedmiot*>::iterator it_plecak;

	vector<Pokemon*>lista_pokemonow;
	vector<Pokemon*>::iterator it_pok;
	void setXY(float x, float y);
	Gracz();
	~Gracz();
	Texture ethan_tex;
	//map<string, Gracz> Lista_aktorow;
	//map<string, Gracz>::iterator it;
	Gracz(float Tx, float Ty);

	void setGold(int ilosc);
	int getGold();
	void dodaj_pokemona(Pokemon* pok);
	Pokemon* getPokemon(int indeks);
	vector<Pokemon*> getlista_pok();
	bool czy_ma_pokemony();
	Pokemon* wybierz_pierwszego();
	vector<Pokemon*>::iterator get_it();
	void set_it();
	void ulecz_pokemony();
};



class NPC :
	public Actors
{
	NPC();

	~NPC();
};
