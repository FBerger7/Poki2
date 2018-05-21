#include"Engine.h"

void Engine::input()
{
	Event zdarzenie;
	while (m_Window.pollEvent(zdarzenie))
	{
		switch (zdarzenie.type)
		{
		case Event::Closed:
			m_Window.close();
			break;
		case Event::KeyPressed:
		{
			if (zdarzenie.key.code == Keyboard::Right)
			{
				if (!map1->check_colision(RIGHT, ethan))
				{
					ethan.set_ym(ethan.get_ym() + 1);
					//map1->wypisz(ethan.get_xm(), ethan.get_ym());
					ethan.Lista_aktorow.at("ethan").move(RIGHT);
					view.move(16, 0);
					//m_Window.setView(view);
				}
			}
			else if (zdarzenie.key.code == Keyboard::Up)
			{
				if (!map1->check_colision(UP, ethan))
				{
					ethan.set_xm(ethan.get_xm() - 1);
					//map1->wypisz(ethan.get_xm(), ethan.get_ym());
					ethan.Lista_aktorow.at("ethan").move(UP);
					view.move(0, -16);
					//m_Window.setView(view);
				}
			}
			else if (zdarzenie.key.code == Keyboard::Down)
			{
				if (!map1->check_colision(DOWN, ethan))
				{
					ethan.set_xm(ethan.get_xm() + 1);
					//map1->wypisz(ethan.get_xm(), ethan.get_ym());
					ethan.Lista_aktorow.at("ethan").move(DOWN);
					view.move(0, 16);
					//m_Window.setView(view);
				}
			}
			else if (zdarzenie.key.code == Keyboard::Left)
			{
				if (!map1->check_colision(LEFT, ethan))
				{
					ethan.set_ym(ethan.get_ym() - 1);
					//map1->wypisz(ethan.get_xm(),ethan.get_ym());
					ethan.Lista_aktorow.at("ethan").move(LEFT);
					view.move(-16, 0);
					//m_Window.setView(view);
				}
			}
			break;
		}
		default: break;
		}
	}
}