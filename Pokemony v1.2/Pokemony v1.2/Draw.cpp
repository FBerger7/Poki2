#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(Color::White);
	m_Window.setView(view);
	m_Window.draw(m_BackgroundSprite);
	for (ethan.it = ethan.Lista_aktorow.begin(); ethan.it != ethan.Lista_aktorow.end(); ethan.it++)
	{
		m_Window.draw(ethan.it->second);
	}

	m_Window.display();
}