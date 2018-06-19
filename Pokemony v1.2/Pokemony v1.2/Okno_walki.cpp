#include "Sceny.h"

Okno_walki::Okno_walki(RenderWindow & m_Window,Gracz ethan)
{
	koniec_walki = false;
	IntRect wymiary_okna(0, 0, 800, 600);
	try
	{
		if (!BackgroundTexture.loadFromFile("Battle_template.png"))
			throw BaseException("Nie udalo sie wczytac pliku Battle_template.png");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setTextureRect(wymiary_okna);

	gracz = ethan;
	hp_przeciwnika.setPosition(97, 62); //polozenia paska hp
	hp_sojusznika.setPosition(581, 330);

	exp.setPosition(520, 382);
	exp.setFillColor(Color::Blue);

	create(m_Window);

	wybierz_akcje = new Menu_walki();

}

Okno_walki::Okno_walki(RenderWindow & m_Window, Gracz ethan, NPC *gym_leader)
{
	koniec_walki = false;
	IntRect wymiary_okna(0, 0, 800, 600);
	try
	{
		if (!BackgroundTexture.loadFromFile("Battle_template.png"))
			throw BaseException("Nie udalo sie wczytac pliku Battle_template.png");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setTextureRect(wymiary_okna);

	gracz = ethan;
	hp_przeciwnika.setPosition(97, 62); //polozenia paska hp
	hp_sojusznika.setPosition(581, 330);

	exp.setPosition(520, 382);
	exp.setFillColor(Color::Blue);

	create(m_Window, gym_leader);

	wybierz_akcje = new Menu_walki();
}

Okno_walki::~Okno_walki()
{
	delete(wybierz_akcje);
	if (usun_przeciwnika)
		delete(Przeciwnik);
};

///////////////////////////////////////////////////////////

void Okno_walki::create(RenderWindow &m_Window)//parametry: przciwnik(gracz/pokemon)
{
	//PRZECIWNIK
	usun_przeciwnika = true;
	int jaki_przeciwnik = rand() % 2;
	int lvl_przeciwnika = (rand() % 4) + 4;
	switch (jaki_przeciwnik)
	{
		case 0:
			Przeciwnik = new Poliwrath(lvl_przeciwnika, false);
			break;
		case 1:
			Przeciwnik = new Stelfozaur(lvl_przeciwnika, false);
			break;
		case 2:
			break;
	}

	hp_przeciwnika.setSize(Vector2f(181 * Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP(), 8));//rozmiar paska zycia
	hp_przeciwnika.setFillColor(Color::Green);

	//SOJUSZNIK
	Sojusznik = gracz.wybierz_pierwszego();
	hp_sojusznika.setSize(Vector2f(184 * Sojusznik->getC_HP() / Sojusznik->getMAX_HP(), 8)); //rozmiar paska zycia
	if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 1 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.5)
		hp_sojusznika.setFillColor(Color::Green);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.5 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.25)
		hp_sojusznika.setFillColor(Color::Yellow);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.25 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0)
		hp_sojusznika.setFillColor(Color::Red);

	exp.setSize(Vector2f(245 * Sojusznik->getC_EXP() / Sojusznik->getMAX_EXP(), 4)); //rozmiar paska exp
}

void Okno_walki::create(RenderWindow & m_Window, NPC *gym_leader)
{
	usun_przeciwnika = true;

	//PRZECIWNIK
	Przeciwnik = gym_leader->wybierz_pierwszego();
	hp_przeciwnika.setSize(Vector2f(181 * Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP(), 8));//rozmiar paska zycia
	hp_przeciwnika.setFillColor(Color::Green);

	//SOJUSZNIK
	Sojusznik = gracz.wybierz_pierwszego();
	hp_sojusznika.setSize(Vector2f(184 * Sojusznik->getC_HP() / Sojusznik->getMAX_HP(), 8)); //rozmiar paska zycia
	if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 1 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.5)
		hp_sojusznika.setFillColor(Color::Green);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.5 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.25)
		hp_sojusznika.setFillColor(Color::Yellow);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.25 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0)
		hp_sojusznika.setFillColor(Color::Red);

	exp.setSize(Vector2f(245 * Sojusznik->getC_EXP() / Sojusznik->getMAX_EXP(), 4)); //rozmiar paska exp
}

void Okno_walki::update(RenderWindow & m_Window, Gracz & ethan)
{
	atak(ethan);
	//Ustawianie koloru paska zycia----------------------------------
	hp_przeciwnika.setSize(Vector2f(181 * (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP()), 8));
	if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 1 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0.5)
		hp_przeciwnika.setFillColor(Color::Green);
	else if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 0.5 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0.25)
		hp_przeciwnika.setFillColor(Color::Yellow);
	else if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 0.25 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0)
		hp_przeciwnika.setFillColor(Color::Red);

	hp_sojusznika.setSize(Vector2f(184 * Sojusznik->getC_HP() / Sojusznik->getMAX_HP(), 8)); //rozmiar paska zycia
	if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 1 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.5)
		hp_sojusznika.setFillColor(Color::Green);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.5 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.25)
		hp_sojusznika.setFillColor(Color::Yellow);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.25 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0)
		hp_sojusznika.setFillColor(Color::Red);
	//---------------------------------------------------------------
}


void Okno_walki::update(RenderWindow &m_Window, Gracz &ethan, NPC *gym_leader)
{
		atak(ethan, gym_leader);
		//Ustawianie koloru paska zycia----------------------------------
		hp_przeciwnika.setSize(Vector2f(181 * (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP()), 8));
		if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 1 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0.5)
		hp_przeciwnika.setFillColor(Color::Green);
		else if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 0.5 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0.25)
		hp_przeciwnika.setFillColor(Color::Yellow);
		else if (Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() <= 0.25 && Przeciwnik->getC_HP() / Przeciwnik->getMAX_HP() > 0)
		hp_przeciwnika.setFillColor(Color::Red);

		hp_sojusznika.setSize(Vector2f(184 * Sojusznik->getC_HP() / Sojusznik->getMAX_HP(), 8)); //rozmiar paska zycia
		if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 1 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.5)
			hp_sojusznika.setFillColor(Color::Green);
		else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.5 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.25)
			hp_sojusznika.setFillColor(Color::Yellow);
		else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.25 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0)
			hp_sojusznika.setFillColor(Color::Red);
		//---------------------------------------------------------------
};
void Okno_walki::draw(RenderWindow &m_Window)
{
	m_Window.clear(Color::White);
	m_Window.draw(BackgroundSprite);

	m_Window.draw(Przeciwnik->getSprite());
	m_Window.draw(Sojusznik->getSprite());

	m_Window.draw(Przeciwnik->getNazwa());
	m_Window.draw(Sojusznik->getNazwa());


	m_Window.draw(Przeciwnik->getLevel());
	m_Window.draw(Sojusznik->getLevel());

	m_Window.draw(Sojusznik->getC_HP_txt());
	m_Window.draw(Sojusznik->getMAX_HP_txt());

	m_Window.draw(hp_przeciwnika);
	m_Window.draw(hp_sojusznika);
	m_Window.draw(exp);

	m_Window.draw(wybierz_akcje->getSprite());

	for (int i = 0; i < Sojusznik->lista_atakow.size(); i++)
		m_Window.draw(Sojusznik->lista_atakow[i]->getNazwa());
}
bool Okno_walki::czyKoniec()
{
	return koniec_walki;
}

void Okno_walki::atak(Gracz & ethan)
{
	int CRIT = rand() % 10;
	float damage;
	cout << Sojusznik->lista_atakow.size();
	cout << wybierz_akcje->getIndeks();
	if ((wybierz_akcje->getIndeks()) <= Sojusznik->lista_atakow.size())
	{
		//Atak gracza
		damage = Sojusznik->lista_atakow[wybierz_akcje->getIndeks() - 1]->getSila();
		damage *= Sojusznik->getATK();
		if (CRIT = 0) damage *= 2;
		Przeciwnik->setC_HP(damage - (Przeciwnik->getDEF()*0.1f));
		if (Przeciwnik->getC_HP() <= 0)
		{
			koniec_walki = true; //koniec walki
			wygrana_walka(ethan);
		}
		else { //ATAK przeciwnika
			damage = Przeciwnik->lista_atakow[rand() % Przeciwnik->lista_atakow.size()]->getSila();
			damage *= Przeciwnik->getATK();
			if (damage - (Sojusznik->getDEF()*0.2f) <= 0) damage = 1;
			else damage -= (Sojusznik->getDEF()*0.2f);
			Sojusznik->setC_HP(damage);
			if (Sojusznik->getC_HP() <= 0)
			{
				if (gracz.czy_ma_pokemony())
					Sojusznik = gracz.wybierz_pierwszego();
				else
					koniec_walki = true;
			}
			Sojusznik->setHP_txt();
		}
	}
	else cout << "Brak ataku w tym miejscu";
}

void Okno_walki::atak(Gracz &ethan, NPC *gym_leader)
{
	int CRIT = rand() % 10;
	float damage;
	cout << Sojusznik->lista_atakow.size();
	cout << wybierz_akcje->getIndeks();
	if ((wybierz_akcje->getIndeks()) <= Sojusznik->lista_atakow.size())
	{
		//Atak gracza
		damage = Sojusznik->lista_atakow[wybierz_akcje->getIndeks()-1]->getSila();
		damage *= Sojusznik->getATK();
		if (CRIT = 0) damage *= 2;
		Przeciwnik->setC_HP(damage - (Przeciwnik->getDEF()*0.1f));
		if (Przeciwnik->getC_HP() <= 0)
		{
			if (gym_leader->czy_ma_pokemony())
				Przeciwnik = gym_leader->wybierz_pierwszego();
			else
			{
				koniec_walki = true; //koniec walki
				wygrana_walka(ethan);
			}
		}
		else { //ATAK przeciwnika
			damage = Przeciwnik->lista_atakow[rand()%Przeciwnik->lista_atakow.size()]->getSila();
			damage *= Przeciwnik->getATK();
			if (damage - (Sojusznik->getDEF()*0.2f) <= 0) damage = 1;
			else damage -= (Sojusznik->getDEF()*0.2f);
			Sojusznik->setC_HP(damage);
			if (Sojusznik->getC_HP() <= 0)
			{
				if (gracz.czy_ma_pokemony())
					Sojusznik = gracz.wybierz_pierwszego();
				else
					koniec_walki = true;
			}
			Sojusznik->setHP_txt();
		}
	}
	else cout << "Brak ataku w tym miejscu";
}

void Okno_walki::wygrana_walka(Gracz &ethan)
{
	float exp = Przeciwnik->getLVL() * 1.4 * 25;
	Sojusznik->setC_EXP(exp);
	ethan.setGold(gracz.getGold() + Przeciwnik->getLVL()*((rand() % 4) + 3));
}

void Okno_walki::setSojusznik(Pokemon * nowy_sojusznik)
{
	Sojusznik = nowy_sojusznik;

	hp_sojusznika.setSize(Vector2f(184 * Sojusznik->getC_HP() / Sojusznik->getMAX_HP(), 8)); //rozmiar paska zycia
	if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 1 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.5)
		hp_sojusznika.setFillColor(Color::Green);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.5 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.25)
		hp_sojusznika.setFillColor(Color::Yellow);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.25 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0)
		hp_sojusznika.setFillColor(Color::Red);

	exp.setSize(Vector2f(245 * Sojusznik->getC_EXP() / Sojusznik->getMAX_EXP(), 4)); //rozmiar paska exp
}

void Okno_walki::uleczSojusznika(float heal)
{
	Sojusznik->heal(heal);

	hp_sojusznika.setSize(Vector2f(184 * Sojusznik->getC_HP() / Sojusznik->getMAX_HP(), 8)); //rozmiar paska zycia
	if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 1 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.5)
		hp_sojusznika.setFillColor(Color::Green);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.5 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0.25)
		hp_sojusznika.setFillColor(Color::Yellow);
	else if (Sojusznik->getC_HP() / Sojusznik->getMAX_HP() <= 0.25 && Sojusznik->getC_HP() / Sojusznik->getMAX_HP() > 0)
		hp_sojusznika.setFillColor(Color::Red);
}

void Okno_walki::lapPrzeciwnika(Gracz & ethan,int szansa)
{
	int tmp = (rand() % 10) + 5;
	szansa += 1/Przeciwnik->stosunek_hp();
	if (szansa >= tmp)
	{
		Przeciwnik->zrob_sojusznik();
		ethan.dodaj_pokemona(Przeciwnik);
		koniec_walki = true;
		usun_przeciwnika = false;
	} 
}
