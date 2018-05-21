#include "Sceny.h"

Okno_eksploracji::Okno_eksploracji()
{
	IntRect wym1(0, 0, 1470, 576);
	m_BackgroundTexture.loadFromFile("Town3.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	m_BackgroundSprite.setTextureRect(wym1);
	m_BackgroundSprite.setOrigin(22, 0);

};

Okno_eksploracji::~Okno_eksploracji()
{

};

////////////////////////////////////////////////////////////

void Okno_eksploracji::create(RenderWindow &m_Window)
{

};

void Okno_eksploracji::draw(RenderWindow &m_Window)
{
	m_Window.clear(Color::White);
	m_Window.draw(m_BackgroundSprite);
};