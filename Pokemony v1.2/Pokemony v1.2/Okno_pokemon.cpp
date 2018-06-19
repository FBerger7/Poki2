#include "Okno_pokemon.h"



Okno_pokemon::Okno_pokemon(RenderWindow &m_Window)
{
	IntRect wymiary_okna(0, 0, 800, 600);
	try
	{
		if (!BackgroundTexture.loadFromFile("Pokemon_ramka.png"))
			throw BaseException("Nie udalo sie wczytac pliku Pokemon_ramka.png");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setTextureRect(wymiary_okna);

	try
	{
		if (!KursorTexture.loadFromFile("Kursor.png"))
			throw BaseException("Nie udalo sie wczytac pliku Kursor.png");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}
	KursorSprite.setTexture(KursorTexture);
	KursorSprite.setPosition(70.f, 80.f);
	indeks = 0;

	zaznaczenie_bool = -1;
	zaznaczenie.setSize(Vector2f(639.f, 112.f));
}


Okno_pokemon::~Okno_pokemon()
{
}

void Okno_pokemon::move_kursor(Direction y)
{
	switch (y)
	{
	case DOWN:
		if (KursorSprite.getPosition().y <= (-15.2f + 95.2*liczba_pokemonow_ethana))
		{
			KursorSprite.setPosition(Vector2f(KursorSprite.getPosition().x, KursorSprite.getPosition().y + 95.2f));
			indeks++;
		}
		break;
	case UP:
		if (KursorSprite.getPosition().y > 80.f)
		{
			KursorSprite.setPosition(Vector2f(KursorSprite.getPosition().x, KursorSprite.getPosition().y - 95.2f));
			indeks--;
		}
		break;
	}
}

void Okno_pokemon::create(RenderWindow & m_Window)
{

}

void Okno_pokemon::draw(RenderWindow & m_Window, Gracz ethan)
{
	m_Window.clear(Color::White);
	m_Window.draw(BackgroundSprite);
	m_Window.draw(KursorSprite);
	int i = 0;
	for (ethan.it_pok = ethan.lista_pokemonow.begin(); ethan.it_pok != ethan.lista_pokemonow.end(); ethan.it_pok++)
	{
		//WYswitlanie tekstury pokemona
		m_Window.draw((*ethan.it_pok)->getSprite_menu(i));
		//Wyswietlanie HP
		Text pom = (*ethan.it_pok)->getC_HP_txt();
		pom.setPosition(600.f, 70.f + i*95.2);
		pom.setString(to_string((int)floor((*ethan.it_pok)->getC_HP()+0.5)) + " / " + to_string((int)floor((*ethan.it_pok)->getMAX_HP()+0.5)));
		m_Window.draw(pom);

		//Wyswietlanie Nazwy
		pom = (*ethan.it_pok)->getNazwa();
		pom.setCharacterSize(14);
		pom.setPosition(250.f, 70.f + i * 95.2);
		m_Window.draw(pom);

		//Wyswietlanie levela
		pom = (*ethan.it_pok)->getLevel();
		pom.setCharacterSize(14);
		pom.setPosition(250.f, 100.f + i * 95.2);
		string tmp = "Lv. " + pom.getString();
		pom.setString(tmp);
		m_Window.draw(pom);

		//Wyswietlanie paska hp
		RectangleShape hp;
		hp.setPosition(350.f, 100.f + i * 95.2);
		hp.setSize(Vector2f(315.f * (*ethan.it_pok)->stosunek_hp() , 14.f));
		if ((*ethan.it_pok)->stosunek_hp() < 0.5 && (*ethan.it_pok)->stosunek_hp() > 0.25)
			hp.setFillColor(Color::Yellow);
		else if ((*ethan.it_pok)->stosunek_hp() < 0.25)
			hp.setFillColor(Color::Red);
		else hp.setFillColor(Color::Green);
		m_Window.draw(hp);

		i++;
	}
	//Wyswietlanie zaznazczenia
	if (zaznaczenie_bool != -1)
		m_Window.draw(zaznaczenie);

	liczba_pokemonow_ethana = ethan.lista_pokemonow.size()-1;
}

int Okno_pokemon::swap()
{
	int pom = indeks;
	zresetuj_kursor();
	return pom;
}

void Okno_pokemon::zaznacz()
{
	zaznaczenie.setPosition(Vector2f(111.f , 44.f + indeks*95.2f));
	zaznaczenie_bool = indeks;
}

void Okno_pokemon::swap(Gracz & ethan)
{
	Pokemon* pom = ethan.lista_pokemonow[zaznaczenie_bool];
	ethan.lista_pokemonow[zaznaczenie_bool] = ethan.lista_pokemonow[indeks];
	ethan.lista_pokemonow[indeks] = pom;
	setZaznaczenie();
}

void Okno_pokemon::zresetuj_kursor()
{
	KursorSprite.setPosition(70.f, 80.f);
	indeks = 0;
}

void Okno_pokemon::setZaznaczenie()
{
	zaznaczenie_bool = -1;
}

int Okno_pokemon::getZaznaczenie()
{
	return zaznaczenie_bool;
}
