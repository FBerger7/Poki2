#include "Mapa.h"

void Tile::set_tile_colision(tile_type T, Tile *pom)
{
	pom->colision = true;
}

void Tile::set_tile_no_colision(tile_type T, Tile *pom)
{
	pom->colision = false;
	if (T == GRASS)
		pom->is_grass = true;
}

bool Tile::tile_is_grass()
{
	if (is_grass)
		return true;
	else return false;
}

bool Tile::return_colision()
{
	return colision;
}

bool Mapa::is_grass(int _x, int _y)
{
	if (tab[_x][_y]->tile_is_grass())
		return true;
	else return false;
}


Mapa::Mapa()
{
	fstream plik;
	plik.open("Mapa.txt", ios::in);
	if (plik.good() == true)
	{
		char x;
		for (int i = 0; i<36; i++)
			for (int j = 0; j<56; j++)
			{
				plik >> x;
				if (x == '0')
				{
					Tile * tmp = new Tile();
					tab[i][j] = tmp;
					tmp->set_tile_no_colision(NORMAL, tmp);
				}
				if (x == '1' || x == '3')
				{
					Tile * tmp = new Tile();
					tab[i][j] = tmp;
					tmp->set_tile_colision(NORMAL, tmp);
				}
				if (x == '2')
				{
					Tile * tmp = new Tile();
					tab[i][j] = tmp;
					tmp->set_tile_no_colision(GRASS, tmp);
				}
			}
	}
	else
		cout << "Nie udalo sie otworzyc pliku mapy" << endl;
	plik.close();
}

void Mapa::set_starting_position(Gracz ethan)
{
	ethan.set_xm(25);
	ethan.set_ym(9);
}


bool Mapa::check_colision(Direction D, Gracz ethan)
{
	if (D == RIGHT)
		return tab[ethan.get_xm()][ethan.get_ym() + 1]->return_colision();
	else if (D == LEFT)
		return tab[ethan.get_xm()][ethan.get_ym() - 1]->return_colision();
	else if (D == DOWN)
		return tab[ethan.get_xm() + 1][ethan.get_ym()]->return_colision();
	else if (D == UP)
		return tab[ethan.get_xm() - 1][ethan.get_ym()]->return_colision();
}

void Mapa::wypisz(int x, int y)
{
	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (i == x && j == y)
			{
				cout << "X";
			}
			else
			{
				if (tab[i][j]->return_colision())
					cout << "1";
				else
					cout << "0";
			}
		}
		cout << endl;
	}
}

Mapa::~Mapa()
{
}
