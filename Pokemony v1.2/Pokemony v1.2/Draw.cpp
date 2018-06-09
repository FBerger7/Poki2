#include "Engine.h"

void Engine::draw()
{
	if (menu_pokemon == true)
	{
		m_Window.setView(view_pokemon);
		pokemon_window->draw(m_Window);
	}
	else
	{
		if (walka == false) 
		{
			m_Window.setView(view_e);
			if (is_in_gym)
			{
				//m_Window.setView(view_budynku);
				GYM->draw(m_Window);
			}
			else
				mapa->draw(m_Window);
			for (it = Lista_aktorow.begin(); it != Lista_aktorow.end(); it++)
			{
				m_Window.draw(it->second->getosoba());
			}
		}
		else
		{
			m_Window.setView(view_b);
			pojedynek->draw(m_Window);
		}
	}
	m_Window.display();
}