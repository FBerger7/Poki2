#include"Engine.h"

void Engine::input()
{
	Event zdarzenie;
	while (m_Window.pollEvent(zdarzenie))
	{
		if (menu_pokemon == true)
		{

		}
		else
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
							Lista_aktorow.at("ethan")->move(RIGHT);
							view_e.move(16, 0);
							if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
								if (czy_jest_walka())
								{
									pojedynek = new Okno_walki(m_Window, ethan);
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
							Lista_aktorow.at("ethan")->move(UP);
							view_e.move(0, -16);
							if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
								if (czy_jest_walka())
								{
									pojedynek = new Okno_walki(m_Window, ethan);
									walka = true;
								}
							if (map1->check_door(ethan.get_xm(), ethan.get_ym()))
							{
								if (ethan.get_xm() == 23 && ethan.get_ym() == 46)
								{
									map1 = new Mapa("Mapa_GYM.txt", 20, 12);
									IntRect wymiar_dla_gyma(646, 2, 160, 288);
									GYM = new Okno_eksploracji("GYM2.png", wymiar_dla_gyma);
									delete mapa;
									is_in_gym = true;
									ethan.set_xm(18);
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
							Lista_aktorow.at("ethan")->move(DOWN);
							view_e.move(0, 16);
							if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
								if (czy_jest_walka())
								{
									pojedynek = new Okno_walki(m_Window, ethan);
									walka = true;
								}
							if (is_in_gym)
							{
								if (map1->check_door(ethan.get_xm(), ethan.get_ym()))
								{
									is_in_gym = false;
									delete GYM;
									//Vector2f offset(0,-16);
									//mapa.move(offset);
									mapa = new Okno_eksploracji();
									map1 = new Mapa("Mapa.txt", 36, 56);
									ethan.set_xm(24);
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
							Lista_aktorow.at("ethan")->move(LEFT);
							view_e.move(-16, 0);
							if(map1->is_grass(ethan.get_xm(),ethan.get_ym()))
							if (czy_jest_walka())
							{
								pojedynek = new Okno_walki(m_Window, ethan);
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
			{
				if(pojedynek->czyKoniec()==false)
					switch (zdarzenie.type)
					{
						case Event::Closed:
							m_Window.close();
							break;
						case Event::KeyPressed:
						{
							if (zdarzenie.key.code == Keyboard::Up)
							{
								pojedynek->wybierz_akcje->move(UP);
							}
							else if (zdarzenie.key.code == Keyboard::Down)
							{
								pojedynek->wybierz_akcje->move(DOWN);
							}
							else if (zdarzenie.key.code == Keyboard::Left)
							{
								pojedynek->wybierz_akcje->move(LEFT);
							}
							else if (zdarzenie.key.code == Keyboard::Right)
							{
								pojedynek->wybierz_akcje->move(RIGHT);
							}
							else if (zdarzenie.key.code == Keyboard::X)
							{
								if (pojedynek->wybierz_akcje->getRodzaj() == Walka)
									pojedynek->wybierz_akcje->move(BACK);
								else if (pojedynek->wybierz_akcje->getRodzaj() == Menu)
								{
									pojedynek->wybierz_akcje->move(EXIT);
								}
							}			
							else if (zdarzenie.key.code == Keyboard::Z)
							{
								switch (pojedynek->wybierz_akcje->getRodzaj())
								{
								case Menu:
									pojedynek->wybierz_akcje->akcja();	//wybor walka/plecak/pokemony/ucieczka
									break;
								case Walka:
									pojedynek->update();
									break;
								case Lista_pokemon:
									menu_pokemon = true;
									pojedynek->wybierz_akcje->akcja();
									break;
								}								
								if (pojedynek->wybierz_akcje->getWyjdz_z_walki() == true)
								{
									delete pojedynek;
									walka = false;
								}
								break;
							}
							break;
						}
					default: break;
					}
				else
				{
					delete pojedynek;
					walka = false;
				}
			}
		}
	}
}