#include"Engine.h"

bool Engine::czy_jest_walka()
{
	RANDOM_NUMBER = rand() % 100;
	cout << RANDOM_NUMBER << endl;
	if ( RANDOM_NUMBER < 15)
		return true;
	else
		return false;
}

Engine::Engine()
{
	m_Window.create(VideoMode(800, 600), "Pokemon");
	srand(time(NULL));
	//LISTA NPC
	
	Gracz *pom = new Gracz(1024, 150);
	Lista_aktorow.insert(pair<string, Actors*>("ethan", pom));

	ethan.setGold(700);
	
	//------------Ladowanie muzyki------------------
	try
	{
		if (!gym_music.openFromFile("Gym_sound.wav"))
			throw BaseException("Nie udalo sie wczytac muzyki z GYM'u");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		if (!cerulean_music.openFromFile("City_sound.wav"))
			throw BaseException("Nie udalo sie wczytac muzyki z miasta");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		if (!vs_poke_battle_music.openFromFile("vs_wild_poke_sound.wav"))
			throw BaseException("Nie udalo sie wczytac muzyki z walki vs pokemon");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		if (!route_music.openFromFile("route_music.wav"))
			throw BaseException("Nie udalo sie wczytac route muzyki");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		if (!poke_center_music.openFromFile("pokemon-center.wav"))
			throw BaseException("Nie udalo sie wczytac muzyki z PokeCenter");
	}
	catch (const BaseException &e)
	{
		cout << e.what() << endl;
	}

	//---------------------------------------------

	Pokemon* tmp = new Poliwrath(5, true);
	ethan.dodaj_pokemona(tmp);
	tmp = new Stelfozaur(5, true);
	ethan.dodaj_pokemona(tmp);
	tmp = new Stelfozaur(5, true);
	ethan.dodaj_pokemona(tmp);
	ethan.dodaj_przedmiot(new PokeBall(1));
	ethan.dodaj_przedmiot(new PokeBall(1));
	ethan.dodaj_przedmiot(new Potion(1));
	ethan.dodaj_przedmiot(new Potion(1));
	mapa = new Okno_eksploracji();
	cerulean_music.play();

	map1 = new Mapa("Mapa.txt", 36, 56);
	ethan.ustaw_pozycje(1024, 150);
	
	view_e.setSize(sf::Vector2f(800, 600));
	view_e.setCenter(sf::Vector2f(ethan.getX(), ethan.getY()));
	view_e.zoom(0.3f);

	view_b.setSize(sf::Vector2f(800, 600));
	view_b.setCenter(Vector2f(400, 300));

	pokemon_window = new Okno_pokemon(m_Window);
	view_pokemon.setSize(sf::Vector2f(800, 600));
	view_pokemon.setCenter(Vector2f(400, 300));
	
	plecak_window = new Okno_przedmiotow();
	view_plecak.setSize(sf::Vector2f(800, 600));
	view_plecak.setCenter(Vector2f(400, 300));

	ethan.set_xm(9);
	ethan.set_ym(29);
}

void Engine::start()
{
	// Timing
	while (m_Window.isOpen())
	{
	/*	thread watek_input(&Engine::input, this);
		thread watek_draw(&Engine::draw, this);
		watek_input.join();
		watek_draw.join();*/
		input();
		update();
		draw();
	}
}

Engine::~Engine()
{
}
