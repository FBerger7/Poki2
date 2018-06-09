#include "Engine.h"

void Engine::draw()
{
	if (menu_pokemon==true)
	{
		m_Window.setView(view_pokemon);
		pokemon_window->draw(m_Window, ethan);
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
			else if (is_in_PokeCenter)
			{
				PokeCenter->draw(m_Window);
			}
			else
				mapa->draw(m_Window);
			for (it = Lista_aktorow.begin(); it != Lista_aktorow.end(); it++)
			{
				m_Window.draw(it->second->getosoba());
			}
		}
		else if (walka)
		{
			m_Window.setView(view_b);
			pojedynek->draw(m_Window);
		}
		if (menu_is_open)
		{
			opcje->draw(m_Window);
		}
	}
	m_Window.display();
}