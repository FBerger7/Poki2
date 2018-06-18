#include "Pokemon.h"

void Pokemon::zrob_sojusznik()
{
	sojusznik = true;
}

void Pokemon::scale_sprite()
{
	PokemonSprite.scale(4.f, 4.f);
}

void Pokemon::ustaw_Nazwe()
{
	font.loadFromFile("arial.ttf");
	Nazwa.setFont(font);
	if (sojusznik)
	{
		Nazwa.setPosition(520.f, 306.f);
		Nazwa.setCharacterSize(17);
	}
	else
	{
		Nazwa.setPosition(38.f, 35.f);
		Nazwa.setCharacterSize(16);
	}
	Nazwa.setStyle(Text::Bold);
	Nazwa.setFillColor(Color::Black);
}

void Pokemon::ustaw_LVL()
{
	font.loadFromFile("arial.ttf");
	Level.setFont(font);
	if (sojusznik)
	{
		Level.setPosition(728.f, 302.f);
		Level.setCharacterSize(19);
	}
	else
	{
		Level.setPosition(246.f, 31.f);
		Level.setCharacterSize(18);
	}
	Level.setStyle(Text::Bold);
	Level.setFillColor(Color::Black);
}

void Pokemon::ustaw_HP_txt()
{
	font.loadFromFile("arial.ttf");
	C_HP_txt.setFont(font);
	MAX_HP_txt.setFont(font);

	int i = (int)floor(C_HP + 0.5);
	C_HP_txt.setString(to_string(i));
	i = (int)floor(MAX_HP + 0.5);
	MAX_HP_txt.setString(to_string(i));

	FloatRect bounds = C_HP_txt.getLocalBounds();

	C_HP_txt.setPosition(645.f - bounds.width,349.f);
	MAX_HP_txt.setPosition(667.f,349.f);

	C_HP_txt.setCharacterSize(17);
	MAX_HP_txt.setCharacterSize(17);

	C_HP_txt.setStyle(Text::Bold);
	C_HP_txt.setFillColor(Color::Black);
	MAX_HP_txt.setStyle(Text::Bold);
	MAX_HP_txt.setFillColor(Color::Black);
}

void Pokemon::setHP_txt()
{
	int i = (int)floor(C_HP + 0.5);
	C_HP_txt.setString(to_string(i));;
}

float Pokemon::stosunek_hp()
{
	return C_HP/MAX_HP;
}

void Pokemon::dodaj_atak(Atak* nowy_atak)
{
	if (lista_atakow.size() < 4)
	{
		lista_atakow.push_back(nowy_atak);
		nowy_atak->setIndeks(lista_atakow.size());
	}

}

void Pokemon::heal()
{
	C_HP = MAX_HP;
}

void Pokemon::heal(float hp)
{
	C_HP += hp;
	if (C_HP > MAX_HP) C_HP = MAX_HP;
}


Text Pokemon::getNazwa()
{
	return Nazwa;
}

Text Pokemon::getLevel()
{
	return Level;
}

Text Pokemon::getC_HP_txt()
{
	return C_HP_txt;
}

Text Pokemon::getMAX_HP_txt()
{
	return MAX_HP_txt;
}

float Pokemon::getATK()
{
	return ATK;
}

float Pokemon::getDEF()
{
	return DEF;
}

float Pokemon::getSPD()
{
	return SPD;
}

float Pokemon::getC_HP()
{
	return C_HP;
}

float Pokemon::getMAX_HP()
{
	return MAX_HP;
}

float Pokemon::getC_EXP()
{
	return C_EXP;
}

float Pokemon::getMAX_EXP()
{
	return MAX_EXP;
}

Sprite Pokemon::getSprite()
{
	return PokemonSprite;
}

Sprite Pokemon::getSprite_menu(int i)
{
	PokemonSprite_menu.setPosition(120.f,50.f + i*95.2);
	return PokemonSprite_menu;
}

int Pokemon::getLVL()
{
	return LVL;
}

void Pokemon::setC_HP(float damage)
{
	C_HP -= damage;
	if (C_HP < 0) C_HP = 0;
	else if (C_HP > MAX_HP) C_HP = MAX_HP;
}

void Pokemon::setC_EXP(float exp)
{
	C_EXP += exp;
	while(C_EXP >= MAX_EXP)
	{
		C_EXP -= MAX_EXP;
		lvl_up();
	}
}

