#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <fstream>
#include<map>
#include<string>
#include"Actors.h"
using namespace std;
using namespace sf;

enum tile_type {
	NORMAL,
	GRASS,
	WATER,
	DOOR
};

class Tile
{
private:
	bool colision = false;
	bool is_grass = false;
public:
	Tile() {};
	void set_tile_colision(tile_type T, Tile * pom);
	void set_tile_no_colision(tile_type T, Tile * pom);
	bool return_colision();
	bool tile_is_grass();
	~Tile() {};
};

class Mapa
{
private:
	Tile *tab[36][56];

public:
	Mapa();
	//void draw(RenderTarget & target, RenderStates state) const;
	bool is_grass(int x, int y);
	void set_starting_position(Gracz ethan);
	bool check_colision(Direction D, Gracz ethan);
	void wypisz(int x, int y);
	~Mapa();
};
