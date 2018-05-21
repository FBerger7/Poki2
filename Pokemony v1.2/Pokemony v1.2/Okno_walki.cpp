#include "Sceny.h"


Okno_walki::Okno_walki()
{
	IntRect wym2(0, 0, 800, 600);
	b_BackgroundTexture.loadFromFile("Battle_template.png");
	b_BackgroundSprite.setTexture(b_BackgroundTexture);
	b_BackgroundSprite.setTextureRect(wym2);

	hp_przeciwnika.setPosition(97, 62); //polozenia paska hp
	hp_przeciwnika.setSize(Vector2f(181, 8));//rozmiar paska zycia
	hp_przeciwnika.setFillColor(Color::Green);

	hp_sojusznika.setPosition(581, 330);
	hp_sojusznika.setSize(Vector2f(184, 8)); //rozmiar paska zycia
	hp_sojusznika.setFillColor(Color::Green);

	exp.setPosition(520, 382);
	exp.setSize(Vector2f(245, 4)); //rozmiar paska exp
	exp.setFillColor(Color::Blue);
};

Okno_walki::~Okno_walki()
{

};

///////////////////////////////////////////////////////////

void Okno_walki::create(RenderWindow &m_Window)//parametry: przciwnik(gracz/pokemon)
{
	m_Window.draw(hp_przeciwnika);
	m_Window.draw(hp_sojusznika);
	m_Window.draw(exp);
};

void Okno_walki::update(RenderWindow &m_Window)
{
	m_Window.draw(hp_przeciwnika);
	m_Window.draw(hp_sojusznika);
};

void Okno_walki::draw(RenderWindow &m_Window)
{
	m_Window.clear(Color::White);
	m_Window.draw(b_BackgroundSprite);
	m_Window.draw(hp_przeciwnika);
	m_Window.draw(hp_sojusznika);
	m_Window.draw(exp);
};