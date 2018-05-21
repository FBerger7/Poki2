#include"Engine.h"

Engine::Engine()
{
	m_Window.create(VideoMode(800, 600), "Pokemon");

	//LISTA NPC
	
	Gracz *pom = new Gracz(1024, 144);
	ethan.Lista_aktorow.insert(pair<string, Gracz>("ethan", *pom));
	
	map1 = new Mapa();
	ethan.ustaw_pozycje(1024, 144);
	
	view_e.setSize(sf::Vector2f(800, 600));
	view_e.setCenter(sf::Vector2f(ethan.getX(), ethan.getY()));
	view_e.zoom(0.3f);

	view_b.setSize(sf::Vector2f(800, 600));
	view_b.setCenter(Vector2f(400, 300));
	
	ethan.set_xm(9);
	ethan.set_ym(29);
}

void Engine::start()
{
	// Timing
	while (m_Window.isOpen())
	{

		input();
		update();
		draw();
	}
}