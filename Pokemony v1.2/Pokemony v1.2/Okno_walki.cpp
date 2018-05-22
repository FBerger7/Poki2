#include "Sceny.h"


Okno_walki::Okno_walki()
{
	IntRect wymiary_okna(0, 0, 800, 600);
	b_BackgroundTexture.loadFromFile("Battle_template.png");
	b_BackgroundSprite.setTexture(b_BackgroundTexture);
	b_BackgroundSprite.setTextureRect(wymiary_okna);

	//PRZECIWNIK
	Przeciwnik.scale(5, false);
	hp_przeciwnika.setPosition(97, 62); //polozenia paska hp
	hp_przeciwnika.setSize(Vector2f(181*Przeciwnik.C_HP/Przeciwnik.MAX_HP, 8));//rozmiar paska zycia
	if(Przeciwnik.C_HP / Przeciwnik.MAX_HP <= 1 && Przeciwnik.C_HP / Przeciwnik.MAX_HP > 0.5)
		hp_przeciwnika.setFillColor(Color::Green);
	else if (Przeciwnik.C_HP / Przeciwnik.MAX_HP <= 0.5 && Przeciwnik.C_HP / Przeciwnik.MAX_HP > 0.25)
		hp_przeciwnika.setFillColor(Color::Yellow);
	else if (Przeciwnik.C_HP / Przeciwnik.MAX_HP <= 0.25 && Przeciwnik.C_HP / Przeciwnik.MAX_HP > 0)
		hp_przeciwnika.setFillColor(Color::Red);

	//SOJUSZNIK
	Sojusznik.scale(5, true);
	hp_sojusznika.setPosition(581, 330);
	hp_sojusznika.setSize(Vector2f(184*Sojusznik.C_HP/Sojusznik.MAX_HP, 8)); //rozmiar paska zycia
	if (Sojusznik.C_HP / Sojusznik.MAX_HP <= 1 && Sojusznik.C_HP / Sojusznik.MAX_HP > 0.5)
		hp_sojusznika.setFillColor(Color::Green);
	else if (Sojusznik.C_HP / Sojusznik.MAX_HP <= 0.5 && Sojusznik.C_HP / Sojusznik.MAX_HP > 0.25)
		hp_sojusznika.setFillColor(Color::Yellow);
	else if (Sojusznik.C_HP / Sojusznik.MAX_HP <= 0.25 && Sojusznik.C_HP / Sojusznik.MAX_HP > 0)
		hp_sojusznika.setFillColor(Color::Red);

	exp.setPosition(520, 382);
	exp.setSize(Vector2f(245*Sojusznik.C_EXP/Sojusznik.MAX_EXP, 4)); //rozmiar paska exp
	exp.setFillColor(Color::Blue);
}

Okno_walki::~Okno_walki()
{

};

///////////////////////////////////////////////////////////

void Okno_walki::create(RenderWindow &m_Window)//parametry: przciwnik(gracz/pokemon)
{
	m_Window.draw(Przeciwnik.PokemonSprite);
	m_Window.draw(Sojusznik.PokemonSprite);
	m_Window.draw(hp_przeciwnika);
	m_Window.draw(hp_sojusznika);
	m_Window.draw(exp);
};

void Okno_walki::update(RenderWindow &m_Window)
{
	/*m_Window.draw(hp_przeciwnika);
	m_Window.draw(hp_sojusznika);*/
};
void Okno_walki::draw(RenderWindow &m_Window)
{
	m_Window.clear(Color::White);
	m_Window.draw(b_BackgroundSprite);
	m_Window.draw(Przeciwnik.PokemonSprite);
	m_Window.draw(Sojusznik.PokemonSprite);
	m_Window.draw(hp_przeciwnika);
	m_Window.draw(hp_sojusznika);
	m_Window.draw(exp);
};