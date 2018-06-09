#include "Sceny.h"

Okno_eksploracji::Okno_eksploracji()
{
	IntRect wym1(0, 0, 1470, 576);
	BackgroundTexture.loadFromFile("Town3.png");
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setTextureRect(wym1);
	BackgroundSprite.setOrigin(22, 0);

};

Okno_eksploracji::Okno_eksploracji(string nazwa_budynku, IntRect wymiary, string Is_In)
{
	BackgroundTexture.loadFromFile(nazwa_budynku);
	BackgroundSprite.setTexture(BackgroundTexture);
	//m_BackgroundSprite.setTextureRect(wymiary);
	if(Is_In == "GYM")
		BackgroundSprite.move(1207, 94);
	if(Is_In == "PokeCenter")
		BackgroundSprite.move(1048, 222);
}

Okno_eksploracji::~Okno_eksploracji()
{

};

////////////////////////////////////////////////////////////

void Okno_eksploracji::create(RenderWindow &m_Window)
{

};

void Okno_eksploracji::draw(RenderWindow &m_Window)
{
	m_Window.clear(Color::Black);
	m_Window.draw(BackgroundSprite);
};