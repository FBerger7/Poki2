#include "Okno_pokemon.h"



Okno_pokemon::Okno_pokemon(RenderWindow &m_Window)
{
	IntRect wymiary_okna(0, 0, 800, 600);
	BackgroundTexture.loadFromFile("Pokemon_ramka.png");
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setTextureRect(wymiary_okna);
}


Okno_pokemon::~Okno_pokemon()
{
}

void Okno_pokemon::create(RenderWindow & m_Window)
{

}

void Okno_pokemon::draw(RenderWindow & m_Window, Gracz ethan)
{
	m_Window.clear(Color::White);
	m_Window.draw(BackgroundSprite);
	int i = 0;
	for (ethan.it_pok = ethan.lista_pokemonow.begin(); ethan.it_pok != ethan.lista_pokemonow.end(); ethan.it_pok++)
	{
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
}
