#include "Przedmiot.h"


int Przedmiot::getLiczba()
{
	return liczba;
}

void Przedmiot::setLiczba(int i)
{
	liczba += i;
}

Przedmiot::~Przedmiot()
{
}
