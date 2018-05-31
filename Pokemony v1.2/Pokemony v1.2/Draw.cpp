#include "Engine.h"

void Engine::draw()
{
	if (walka == false) 
	{
		m_Window.setView(view_e);
		mapa.draw(m_Window);
		for (ethan.it = ethan.Lista_aktorow.begin(); ethan.it != ethan.Lista_aktorow.end(); ethan.it++)
		{
			m_Window.draw(ethan.it->second);
		}
	}
	else
	{
		m_Window.setView(view_b);
		pojedynek->draw(m_Window);
	}
	m_Window.display();

}