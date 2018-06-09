#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<map>
#include<string>
#include<iostream>


using namespace std;
using namespace sf;

enum Direction {
	RIGHT,
	LEFT,
	DOWN,
	UP
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
public:
	map<string, Gracz> Lista_aktorow;
	map<string, Gracz>::iterator it;
	Gracz();
	Texture ethan_tex;
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
	void setXY(float x, float y);
	float getX();
	float getY();
	~Gracz();
};



class NPC :
	public Actors
{
	NPC();

	~NPC();
};
