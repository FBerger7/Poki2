#include "Actors.h"

//--------------------ACTORS-----------------------

Actors::Actors()
{
}


Actors::~Actors()
{
}


void Actors::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(osoba, state);
};

void Actors::setSprite(Texture &imgpath)
{
	osoba.setTexture(&imgpath);
}

IntRect Actors::ustaw_kierunek_tekstury(Direction D)
{
	IntRect wymiarR(0, 3, 15, 18);
	IntRect wymiarL(28, 3, 15, 18);
	IntRect wymiarD(57, 3, 16, 18);
	IntRect wymiarU(106, 3, 15, 18);
	switch (D)
	{
	case RIGHT:
		return wymiarR;
		break;
	case LEFT:
		return wymiarL;
		break;
	case DOWN:
		return wymiarD;
		break;
	case UP:
		return wymiarU;
		break;
	}
}

void Actors::move(Direction D)
{
	if (D == RIGHT)
	{
		cout << "wchodzi tu" << endl;
		x += 16;
		cout << x << " " << y << endl;
		osoba.setPosition(x, y);
		osoba.setTextureRect(ustaw_kierunek_tekstury(D));
	}
	if (D == LEFT)
	{
		cout << "wchodzi tu" << endl;
		x -= 16;
		cout << x << " " << y << endl;
		osoba.setPosition(x, y);
		osoba.setTextureRect(ustaw_kierunek_tekstury(D));
	}
	if (D == UP)
	{
		cout << "wchodzi tu" << endl;
		y -= 16;
		cout << x << " " << y << endl;
		osoba.setPosition(x, y);
		osoba.setTextureRect(ustaw_kierunek_tekstury(D));
	}
	if (D == DOWN)
	{
		cout << "wchodzi tu" << endl;
		y += 16;
		cout << x << " " << y << endl;
		osoba.setPosition(x, y);
		osoba.setTextureRect(ustaw_kierunek_tekstury(D));
	}
}


void Actors::set_xm(int _x)
{
	xm = _x;
}

void Actors::set_ym(int _y)
{
	ym = _y;
}

RectangleShape Actors::getSprite()
{
	return osoba;
}

void Actors::ustaw_pozycje(float Tx, float Ty)
{
	osoba.setPosition(Tx, Ty);
	x = Tx;
	y = Ty;
}

void Gracz::setXY(float x, float y)
{
	this->x = this->x - x;
	this->y = this->y - y;
}


float Actors::getX()
{
	return x;
}

float Actors::getY()
{
	return y;
}

RectangleShape Actors::getosoba()
{
	return osoba;
}

int Actors::get_xm()
{
	return xm;
}

int Actors::get_ym()
{
	return ym;
}

//--------------------GRACZ------------------------
Gracz::Gracz()
{

}

Gracz::Gracz(float Tx, float Ty)
{
	Vector2f wielkosc_gracza(16, 16);
	ethan_tex.loadFromFile("Ethan.png");
	osoba.setSize(wielkosc_gracza);
	osoba.setOrigin(8, 8);
	setSprite(ethan_tex);
	osoba.setTextureRect(ustaw_kierunek_tekstury(DOWN));
	//osoba.setScale(3, 3);
	ustaw_pozycje(Tx, Ty);
	//Lista_aktorow.insert(pair<string, Gracz>("Ethan", *this));
	//Chyba nie mozna listy aktorow robic lokalnie :(
}

void Gracz::setGold(int ilosc)
{
	this->piniondze = ilosc;
}

int Gracz::getGold()
{
	return this->piniondze;
}


void Gracz::dodaj_pokemona(Pokemon *pok)
{
	lista_pokemonow.push_back(pok);
}

Pokemon * Gracz::getPokemon(int indeks)
{
	return lista_pokemonow[indeks];
}

vector<Pokemon*> Gracz::getlista_pok()
{
	return lista_pokemonow;
}

bool Gracz::czy_ma_pokemony()
{
	for (it_pok = lista_pokemonow.begin(); it_pok != lista_pokemonow.end(); it_pok++)
	{
		if ((*it_pok)->getC_HP() > 0) return true;
	}
	return false;
}

Gracz::~Gracz()
{
}


//--------------------NPC-----------------------

NPC::NPC()
{

}

NPC::~NPC()
{

}