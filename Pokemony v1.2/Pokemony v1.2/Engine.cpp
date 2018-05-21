#include"Engine.h"

Engine::Engine()
{
	IntRect wym1(0, 0, 1470, 576);
	m_Window.create(VideoMode(800, 600), "Pokemon");
	m_BackgroundTexture.loadFromFile("Town3.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	m_BackgroundSprite.setTextureRect(wym1);
	//m_BackgroundSprite.scale(3, 3);
	m_BackgroundSprite.setOrigin(22, 0);
	map1 = new Mapa();
	Gracz *pom = new Gracz(1024, 144);
	ethan.ustaw_pozycje(1024, 144);
	ethan.Lista_aktorow.insert(pair<string, Gracz>("ethan", *pom));
	view.setCenter(sf::Vector2f(ethan.getX(), ethan.getY()));
	view.setSize(sf::Vector2f(200, 200));
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