#pragma once
#include <iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "Biblioteka_Pokemonow.h"
#include <memory>
#include "Menu_walki.h"
#include "Menu.h"
#include "Actors.h"

using namespace std;
using namespace sf;


class Scena_abstrakcyjna :
	public Sprite
{
protected:
	Sprite BackgroundSprite; //battle background
	Texture BackgroundTexture;
public:
	//virtual void create(RenderWindow &m_Window) = 0;
	//~Scena_abstrakcyjna();
};

class Okno_eksploracji : public Scena_abstrakcyjna
{
private:

public:

	Okno_eksploracji();
	~Okno_eksploracji();

	Okno_eksploracji(string nazwa_budynku, IntRect wymiary, string Is_In);
	void create(RenderWindow &m_Window);
	void draw(RenderWindow &m_Window);
};
class Okno_walki : public Scena_abstrakcyjna
{
private:
	Pokemon* Przeciwnik;
	RectangleShape przeciwnik_texture;
	RectangleShape hp_przeciwnika;

	Gracz gracz;
	Pokemon *Sojusznik;
	RectangleShape sojusznik_texture;
	RectangleShape hp_sojusznika;
	RectangleShape exp;
	bool koniec_walki;
	bool usun_przeciwnika;


public:
	Menu_walki *wybierz_akcje;
	Okno_walki(RenderWindow &m_Window,Gracz ethan);
	Okno_walki(RenderWindow &m_Window, Gracz ethan, NPC gym_leader);
	~Okno_walki();
	void create(RenderWindow &m_Window);
	void create(RenderWindow &m_Window, NPC *gym_leader);
	void update(RenderWindow &m_Window, Gracz &ethan);
	void update(RenderWindow &m_Window, Gracz &ethan, NPC *gym_leader);
	void draw(RenderWindow &m_Window);
	bool czyKoniec();
	void atak(Gracz &ethan);
	void atak(Gracz &ethan, NPC *gym_leader);
	void wygrana_walka(Gracz &ethan);
	void setSojusznik(Pokemon* nowy_sojusznik);
	void uleczSojusznika(float heal);
	void lapPrzeciwnika(Gracz &ethan, int szansa);
};

