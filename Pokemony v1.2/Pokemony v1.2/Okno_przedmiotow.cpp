#include "Okno_przedmiotow.h"

Okno_przedmiotow::Okno_przedmiotow()
{
	IntRect wymiary_okna(0, 0, 800, 600);
	BackgroundTexture.loadFromFile("Pokemon_ramka.png");
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setTextureRect(wymiary_okna);

	KursorTexture.loadFromFile("Kursor.png");
	KursorSprite.setTexture(KursorTexture);
	KursorSprite.setPosition(70.f, 80.f);
	indeks = 0;
}

Okno_przedmiotow::~Okno_przedmiotow()
{
}

void Okno_przedmiotow::draw(RenderWindow & m_Window, Gracz ethan)
{
	m_Window.clear(Color::White);
	m_Window.draw(BackgroundSprite);
	m_Window.draw(KursorSprite);
	int i = 0;
	for (ethan.it_plecak = ethan.plecak.begin(); ethan.it_plecak != ethan.plecak.end(); ethan.it_plecak++)
	{
		(*ethan.it_plecak)->setPosition(120, 80 + i * 95.2);
		m_Window.draw((*ethan.it_plecak)->getSprite());
		m_Window.draw((*ethan.it_plecak)->getNazwa());
		m_Window.draw((*ethan.it_plecak)->getIlosc());
		i++;
	}
}

void Okno_przedmiotow::move_kursor(Direction y, Gracz ethan)
{
	switch (y)
	{
	case DOWN:
		if (KursorSprite.getPosition().y <= (-45 + 95*ethan.plecak.size()))
		{
			KursorSprite.setPosition(Vector2f(KursorSprite.getPosition().x, KursorSprite.getPosition().y + 95.2f));
			indeks++;
		}
		break;
	case UP:
		if (KursorSprite.getPosition().y > 80)
		{
			KursorSprite.setPosition(Vector2f(KursorSprite.getPosition().x, KursorSprite.getPosition().y - 95.2f));
			indeks--;
		}
		break;
	}
}

void Okno_przedmiotow::zresetuj_kursor()
{
	KursorSprite.setPosition(70.f, 80.f);
	indeks = 0;
}

int Okno_przedmiotow::getIndeks()
{
	return indeks;
}
