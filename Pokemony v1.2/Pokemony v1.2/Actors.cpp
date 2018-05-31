#include "Actors.h"

//--------------------ACTORS-----------------------

Actors::Actors()
{
}


Actors::~Actors()
{
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

void Gracz::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(osoba, state);
};

void Gracz::setSprite(Texture &imgpath)
{
	osoba.setTexture(&imgpath);
}

IntRect Gracz::ustaw_kierunek_tekstury(Direction D)
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

void Gracz::move(Direction D)
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


void Gracz::set_xm(int _x)
{
	xm = _x;
}

void Gracz::set_ym(int _y)
{
	ym = _y;
}

RectangleShape Gracz::getSprite()
{
	return osoba;
}

void Gracz::ustaw_pozycje(float Tx, float Ty)
{
	osoba.setPosition(Tx, Ty);
	x = Tx;
	y = Ty;
}


float Gracz::getX()
{
	return x;
}

float Gracz::getY()
{
	return y;
}

int Gracz::get_xm()
{
	return xm;
}

int Gracz::get_ym()
{
	return ym;
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