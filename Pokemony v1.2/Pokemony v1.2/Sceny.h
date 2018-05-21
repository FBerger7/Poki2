#pragma once

#include<string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class Scena_abstrakcyjna :
	public Sprite
{
public:
	Scena_abstrakcyjna();
	virtual void create(RenderWindow &m_Window) = 0;
	~Scena_abstrakcyjna();
};

class Okno_eksploracji : public Scena_abstrakcyjna
{
private:
	Sprite m_BackgroundSprite; //battle background
	Texture m_BackgroundTexture;

public:
	Okno_eksploracji();
	~Okno_eksploracji();

	void create(RenderWindow &m_Window);
	void draw(RenderWindow &m_Window);
};

class Okno_walki : public Scena_abstrakcyjna
{
private:
	Sprite b_BackgroundSprite; //battle background
	Texture b_BackgroundTexture;
	RectangleShape hp_przeciwnika;
	RectangleShape hp_sojusznika;
	RectangleShape exp;
public:
	Okno_walki();
	~Okno_walki();
	void create(RenderWindow &m_Window);
	void update(RenderWindow &m_Window);
	void draw(RenderWindow &m_Window);
};