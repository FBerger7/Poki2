#include"Engine.h"

Engine::Engine()
{
	m_Window.create(VideoMode(800, 600), "Pokemon");

	//LISTA NPC
	Gracz *pom = new Gracz(0,0);
	ethan.Lista_aktorow.insert(pair<string, Gracz>("ethan", *pom));
	
	view_e.setSize(sf::Vector2f(800, 600));
	view_e.setCenter(sf::Vector2f(ethan.getX(), ethan.getY()));
	view_e.zoom(0.3f);

	view_b.setSize(sf::Vector2f(800, 600));
	view_b.setCenter(Vector2f(400, 300));

}

void Engine::start()
{
	// Timing
	Clock clock;

	while (m_Window.isOpen())
	{
		// Restart the clock and save the elapsed time into dt
		Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update();
		draw();
	}
}