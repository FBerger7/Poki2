#include"Engine.h"

void Engine::input()
{
	Event zdarzenie;
	while (m_Window.pollEvent(zdarzenie))
	{
		if (walka == false && menu_is_open == false)
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
						ethan.setXY(-16, 0);
						if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
							if (czy_jest_walka())
							{
								pojedynek = new Okno_walki(m_Window, ethan);
								walka = true;
								route_music.stop();
								vs_poke_battle_music.play();
							}
						if (ethan.get_ym() == 16)
						{
							route_music.stop();
							cerulean_music.play();
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
						ethan.setXY(0, 16);
						if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
							if (czy_jest_walka())
							{
								pojedynek = new Okno_walki(m_Window, ethan);
								walka = true;
								route_music.stop();
								vs_poke_battle_music.play();
							}
						if (map1->check_door(ethan.get_xm(), ethan.get_ym()))
						{
							if (ethan.get_xm() == 23 && ethan.get_ym() == 46)
							{
								map1 = new Mapa("Mapa_GYM.txt", 20, 12);
								IntRect wymiar_dla_gyma(646, 2, 160, 288);
								GYM = new Okno_eksploracji("GYM2.png", wymiar_dla_gyma, "GYM");
								delete mapa;
								cerulean_music.stop();
								gym_music.play();
								is_in_gym = true;
								ethan.set_xm(18);
								ethan.set_ym(6);
							}
							if (ethan.get_xm() == 21 && ethan.get_ym() == 35)
							{
								map1 = new Mapa("PokeCenter_colisions.txt", 9, 12);
								IntRect wymiar_dla_PokeCenter(646, 2, 160, 288);
								PokeCenter = new Okno_eksploracji("PokeCenter.png", wymiar_dla_PokeCenter, "PokeCenter");
								delete mapa;
								is_in_PokeCenter = true;
								cerulean_music.stop();
								poke_center_music.play();
								ethan.set_xm(7);
								ethan.set_ym(5);
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
						ethan.setXY(0, -16);
						if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
							if (czy_jest_walka())
							{
								pojedynek = new Okno_walki(m_Window, ethan);
								walka = true;
								route_music.stop();
								vs_poke_battle_music.play();
							}
						if (map1->check_door(ethan.get_xm(), ethan.get_ym()))
						{
							if (is_in_gym)
							{
								is_in_gym = false;
								delete GYM;
								gym_music.stop();
								cerulean_music.play();
								//Vector2f offset(0,-16);
								//mapa.move(offset);
								mapa = new Okno_eksploracji();
								map1 = new Mapa("Mapa.txt", 36, 56);
								ethan.set_xm(24);
								ethan.set_ym(46);
							}
							if (is_in_PokeCenter)
							{
								is_in_PokeCenter = false;
								delete PokeCenter;
								poke_center_music.stop();
								cerulean_music.play();
								mapa = new Okno_eksploracji();
								map1 = new Mapa("Mapa.txt", 36, 56);
								ethan.set_xm(22);
								ethan.set_ym(35);

							}
						}
					}
				}
				else if (zdarzenie.key.code == Keyboard::Left)
				{
					if (!map1->check_colision(LEFT, ethan))
					{
						ethan.set_ym(ethan.get_ym() - 1);
						Lista_aktorow.at("ethan")->move(LEFT);
						view_e.move(-16, 0);
						ethan.setXY(16,0);
						if (map1->is_grass(ethan.get_xm(), ethan.get_ym()))
							if (czy_jest_walka())
							{
								pojedynek = new Okno_walki(m_Window,ethan);
								walka = true;
								route_music.stop();
								vs_poke_battle_music.play();
							}
						if (ethan.get_ym() == 15)
						{
							cerulean_music.stop();
							route_music.play();
						}
						//m_Window.setView(view);
					}
				}
				else if (zdarzenie.key.code == Keyboard::Tab)
				{
					opcje = new Menu();
					opcje->ustaw_pozycje(ethan.getX(),ethan.getY());
					opcje->ustaw_pieniadze(ethan.getGold(), ethan.getX(), ethan.getY());
					menu_is_open = true;
				}
				else if (ethan.get_xm() == 3 && ethan.get_ym() == 4 && zdarzenie.key.code == Keyboard::Z && is_in_PokeCenter)
				{
					Texture pasek;
					pasek.loadFromFile("pasek.png");
					Sprite rozmowa;
					rozmowa.setTexture(pasek);
					rozmowa.setPosition(ethan.getX()-30, ethan.getY()-40);
					rozmowa.setScale(0.2,0.2);
					m_Window.draw(rozmowa);
					m_Window.display();
					Event rozmowa_siostra;
					int flag = 0;
					while (true)
					{
						while (m_Window.pollEvent(rozmowa_siostra))
						{
							cout << "HALOO" << endl;
							switch(rozmowa_siostra.type)
							case Event::KeyPressed:
							{
								if (rozmowa_siostra.key.code == Keyboard::Z)
								{
									flag = 1;
									break;
								}
								else if (rozmowa_siostra.key.code == Keyboard::X)
								{
									flag = 2;
									break;
								}
								break;
							}
						}
					if (flag != 0)
						break;
					}
				}

				break;
			}
			default: break;
			}
		else if (walka)
			if (pojedynek->czyKoniec() == false)
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
					else if (zdarzenie.key.code == Keyboard::X) //cofa
					{
						switch (pojedynek->wybierz_akcje->getRodzaj())
						{
						case Menu_walka:
							pojedynek->wybierz_akcje->move(EXIT);							
							break;
						case Walka:
							pojedynek->wybierz_akcje->move(BACK);
							break;
						case Lista_pokemon:
							menu_pokemon = false;
							pojedynek->wybierz_akcje->move(BACK);

							break;
						}
					}
					else if (zdarzenie.key.code == Keyboard::Z) //zatwierdza
					{
						switch (pojedynek->wybierz_akcje->getRodzaj())
						{
						case Menu_walka:
							pojedynek->wybierz_akcje->akcja(); //wybor walka/plecak/pokemony/ucieczka
							if (pojedynek->wybierz_akcje->getRodzaj() == Lista_pokemon) menu_pokemon = true;
							break;
						case Walka:
							pojedynek->update(m_Window);
							break;
						case Lista_pokemon:
							
							break;
						}
						if (pojedynek->wybierz_akcje->getWyjdz_z_walki() == true)
						{
							delete pojedynek;
							walka = false;
							vs_poke_battle_music.stop();
							route_music.play();
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
				vs_poke_battle_music.stop();
				route_music.play();
			}
		else if (menu_is_open)
			switch (zdarzenie.type)
			{
			case Event::Closed:
				m_Window.close();
				break;
			case Event::KeyPressed:
			{
				if (zdarzenie.key.code == Keyboard::Up)
				{
					opcje->move(UP);
				}
				else if (zdarzenie.key.code == Keyboard::Down)
				{
					opcje->move(DOWN);
				}
				else if (zdarzenie.key.code == Keyboard::Z && opcje->getPozycja() == 0)
				{
					cout << "POKEMOONY TU" << endl;
				}
				else if (zdarzenie.key.code == Keyboard::Z && opcje->getPozycja() == 1)
				{
					cout << "ITEMY TU" << endl;
				}
				else if (zdarzenie.key.code == Keyboard::Z && opcje->getPozycja() == 2)
				{
					cout << "SAVE TU" << endl;
				}
				else if (zdarzenie.key.code == Keyboard::Z && opcje->getPozycja() == 3)
				{
					m_Window.close();
				}
				else if (zdarzenie.key.code == Keyboard::Tab)
				{
					delete opcje;
					menu_is_open = false;
				}
				else if (zdarzenie.key.code == Keyboard::X)
				{
					delete opcje;
					menu_is_open = false;
				}
			}
			default: break;
			}
	}
}