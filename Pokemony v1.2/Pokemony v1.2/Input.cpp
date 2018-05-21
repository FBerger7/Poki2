#include"Engine.h"

void Engine::input()
{
	Event zdarzenie;
	while (m_Window.pollEvent(zdarzenie))
	{
		if(walka==false)
			switch (zdarzenie.type)
			{
			case Event::Closed :
				m_Window.close();
				break;
			case Event::KeyPressed:
			{
				if (zdarzenie.key.code == Keyboard::Right)
				{
					ethan.Lista_aktorow.at("ethan").move(RIGHT);
					view_e.move(16, 0);
					//m_Window.setView(view);
				}
				else if (zdarzenie.key.code == Keyboard::Up)
				{
					ethan.Lista_aktorow.at("ethan").move(UP);
					view_e.move(0, -16);
					//m_Window.setView(view);
				}
				else if (zdarzenie.key.code == Keyboard::Down)
				{
					ethan.Lista_aktorow.at("ethan").move(DOWN);
					view_e.move(0, 16);
					//m_Window.setView(view);
				}
				else if (zdarzenie.key.code == Keyboard::Left)
				{
					ethan.Lista_aktorow.at("ethan").move(LEFT);
					view_e.move(-16, 0);
					//m_Window.setView(view);
				}
				else if (zdarzenie.key.code == Keyboard::W)
				{
					pojedynek.create(m_Window);
					walka = true;
				}
				break;
			}

			default: break;
			}
		else 
			switch (zdarzenie.type)
			{
			case Event::Closed:
				m_Window.close();
				break;
			case Event::KeyPressed:
			{
				if (zdarzenie.key.code == Keyboard::Escape)
				{
					walka = false;
				}			
				break;
			}
			default: break;
			}
	}
}