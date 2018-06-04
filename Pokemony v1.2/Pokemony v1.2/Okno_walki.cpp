#include "Sceny.h"


Okno_walki::Okno_walki()
{

}

Okno_walki::Okno_walki(RenderWindow & m_Window)
{
	IntRect wymiary_okna(0, 0, 800, 600);
	b_BackgroundTexture.loadFromFile("Battle_template.png");
	b_BackgroundSprite.setTexture(b_BackgroundTexture);
	b_BackgroundSprite.setTextureRect(wymiary_okna);

	hp_przeciwnika.setPosition(97, 62); //polozenia paska hp
	hp_sojusznika.setPosition(581, 330);

	exp.setPosition(520, 382);
	exp.setFillColor(Color::Blue);

	create(m_Window);

	wybierz_akcje = new Menu_walki();
	tura_gracza = true;

}

Okno_walki::~Okno_walki()
{
	delete(Przeciwnik);
	delete(Sojusznik);
	delete(wybierz_akcje);

};

///////////////////////////////////////////////////////////

void Okno_walki::create(RenderWindow &m_Window)//parametry: przciwnik(gracz/pokemon)
{
	//PRZECIWNIK
	int jaki_przeciwnik = rand() % 2;
	switch (jaki_przeciwnik)
	{
		case 0:
			Przeciwnik = new Poliwrath(5, false);
			break;
		case 1:
			Przeciwnik = new Stelfozaur(5, false);
			break;
		case 2:
			break;
	}

	hp_przeciwnika.setSize(Vector2f(181 * Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP(), 8));//rozmiar paska zycia
	//if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 1 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0.5)
		hp_przeciwnika.setFillColor(Color::Green);
	/*else if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 0.5 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0.25)
		hp_przeciwnika.setFillColor(Color::Yellow);
	else if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 0.25 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0)
		hp_przeciwnika.setFillColor(Color::Red);*/

	//SOJUSZNIK
	Sojusznik = new Poliwrath(5, true);
	hp_sojusznika.setSize(Vector2f(184 * Sojusznik->getC_HP() / Sojusznik->getMAX_HP(), 8)); //rozmiar paska zycia
	if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 1 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.5)
		hp_sojusznika.setFillColor(Color::Green);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.5 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.25)
		hp_sojusznika.setFillColor(Color::Yellow);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.25 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0)
		hp_sojusznika.setFillColor(Color::Red);

	exp.setSize(Vector2f(245 * Sojusznik->getC_EXP() / Sojusznik->getMAX_EXP(), 4)); //rozmiar paska exp
};

void Okno_walki::update()
{
	if (tura_gracza)
	{
		atak(tura_gracza);
		hp_przeciwnika.setSize(Vector2f(181 * (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP()), 8));
		tura_gracza = false;
	}
	else
	{
		atak(tura_gracza);
		tura_gracza = true;
	}
};
void Okno_walki::draw(RenderWindow &m_Window)
{
	m_Window.clear(Color::White);
	m_Window.draw(b_BackgroundSprite);

	m_Window.draw(Przeciwnik->getSprite());
	m_Window.draw(Sojusznik->getSprite());

	m_Window.draw(Przeciwnik->getNazwa());
	m_Window.draw(Sojusznik->getNazwa());


	m_Window.draw(Przeciwnik->getLevel());
	m_Window.draw(Sojusznik->getLevel());

	m_Window.draw(hp_przeciwnika);
	m_Window.draw(hp_sojusznika);
	m_Window.draw(exp);

	m_Window.draw(wybierz_akcje->getSprite());

	for (int i = 0; i < Sojusznik->lista_atakow.size(); i++)
		m_Window.draw(Sojusznik->lista_atakow[i]->getNazwa());
}
void Okno_walki::atak(bool gracz_atakuje)
{
	float damage;
	cout << Sojusznik->lista_atakow.size();
	cout << wybierz_akcje->getIndeks();
	if (gracz_atakuje)
	{
			if ((wybierz_akcje->getIndeks()) <= Sojusznik->lista_atakow.size())
			{
				damage = Sojusznik->lista_atakow[wybierz_akcje->getIndeks()-1]->getSila() * Sojusznik->getATK();
				Przeciwnik->setC_HP(damage - (Przeciwnik->getDEF()*0.1f));
			}
			else cout << "Brak ataku w tym miejscu";
	}
	else
	{
		damage = Przeciwnik->lista_atakow[rand()%Przeciwnik->lista_atakow.size()]->getSila() * Przeciwnik->getATK();
		Sojusznik->setC_HP(damage - (Sojusznik->getDEF()*0.1f));
	}
};