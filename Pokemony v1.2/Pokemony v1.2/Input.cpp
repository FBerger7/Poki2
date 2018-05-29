#include"Engine.h"

void Engine::input()
{
	Event zdarzenie;
	while (m_Window.pollEvent(zdarzenie))
	{
	if(walka==false)
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
					view_e.move(16, 0);
					if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
						if (czy_jest_walka())
						{
							pojedynek.create(m_Window);
							walka = true;
						}

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
					view_e.move(0, -16);
					if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
						if (czy_jest_walka())
						{
							pojedynek.create(m_Window);
							walka = true;
						}
					if (map1->check_door(ethan.get_xm(), ethan.get_ym()))
					{
						if (ethan.get_xm() == 23 && ethan.get_ym() == 46)
						{
							map1 = new Mapa("Mapa_GYM.txt", 20, 12);
							IntRect wymiar_dla_gyma(646, 2, 288, 160);
							GYM = new Okno_eksploracji("GYM.png", wymiar_dla_gyma);
							is_in_gym = true;
							ethan.set_xm(19);
							ethan.set_ym(6);
							//JAK SIE ODWOLYWAC POTEM WSZEDZIE NP. DO GYM->CHECK_COLISION ITD.
						}

					}
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
					view_e.move(0, 16);
					if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
						if (czy_jest_walka())
						{
							pojedynek.create(m_Window);
							walka = true;
						}
					if (is_in_gym)
					{
						if (map1->check_door(ethan.get_xm(), ethan.get_ym()))
						{
							is_in_gym = false;
							map1 = new Mapa("Mapa.txt", 36, 56);
							ethan.set_xm(23);
							ethan.set_ym(46);
						}
					}
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
					view_e.move(-16, 0);
					if(map1->is_grass(ethan.get_xm(),ethan.get_ym()))
					if (czy_jest_walka())
					{
						pojedynek.create(m_Window);
						walka = true;
					}
					//m_Window.setView(view);
				}
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