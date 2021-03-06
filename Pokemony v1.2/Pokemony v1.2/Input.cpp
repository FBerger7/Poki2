#include"Engine.h"

void Engine::input()
{
	Event zdarzenie;
	while (m_Window.pollEvent(zdarzenie))
	{
		if (walka == false && menu_is_open == false && shop_is_open == false)
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
							if (czy_jest_walka() && ethan.czy_ma_pokemony())
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
							if (czy_jest_walka() && ethan.czy_ma_pokemony())
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
								//Pokemon*tmp = new Stelfozaur(5, true);
								//gymleader->dodaj_pokemona(tmp);
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
							if (ethan.get_xm() == 29 && ethan.get_ym() == 41)
							{
								map1 = new Mapa("PokeMart_colisions.txt", 9, 10);
								IntRect wymiar_dla_PokeCenter(646, 2, 160, 288);
								PokeMart = new Okno_eksploracji("PokeMart.png", wymiar_dla_PokeCenter, "PokeMart");
								delete mapa;
								is_in_PokeMart = true;
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
							if (czy_jest_walka() && ethan.czy_ma_pokemony())
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
							if (is_in_PokeMart)
							{
								is_in_PokeMart = false;
								delete PokeMart;
								mapa = new Okno_eksploracji();
								map1 = new Mapa("Mapa.txt", 36, 56);
								ethan.set_xm(30);
								ethan.set_ym(41);
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
							if (czy_jest_walka() && ethan.czy_ma_pokemony())
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
					opcje = new Menu("MENU");
					opcje->ustaw_pozycje(ethan.getX(),ethan.getY(), "MENU");
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
							switch(rozmowa_siostra.type)
							case Event::KeyPressed:
							{
								if (rozmowa_siostra.key.code == Keyboard::Z)
								{
									ethan.ulecz_pokemony();
									flag = 1;
									break;
								}
								else if (rozmowa_siostra.key.code == Keyboard::X)
								{
									flag = 1;
									break;
								}
								break;
							}
						}
					if (flag != 0)
						break;
					}
				}
				else if (ethan.get_xm() == 5 && ethan.get_ym() == 3 && zdarzenie.key.code == Keyboard::Z && is_in_PokeMart)
				{
					shop = new Menu("SHOP");
					shop->im_in_shop();
					shop->ustaw_pozycje(ethan.getX(), ethan.getY(), "SHOP");
					shop->ustaw_pieniadze(ethan.getGold(), ethan.getX(), ethan.getY());
					shop_is_open = true;
					shop_buy = new Menu("SHOP2");
					shop_buy->ustaw_pozycje(ethan.getX(), ethan.getY(), "SHOP2");
				}
				else if (ethan.get_xm() == 4 && ethan.get_ym() == 4 && zdarzenie.key.code == Keyboard::Z && is_in_gym && ethan.czy_ma_pokemony())
				{
					gym_leader = new NPC(walka_z_bossem);
					pojedynek = new Okno_walki(m_Window, ethan, gym_leader);
					walka = true;
					walka_zNPC = true;
					gym_music.stop();
					vs_poke_battle_music.play();

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
						if (pojedynek->wybierz_akcje->getRodzaj() == Lista_pokemon)
							pokemon_window->move_kursor(UP);
						else if (pojedynek->wybierz_akcje->getRodzaj() == Lista_przedmiotow)
						{
							plecak_window->move_kursor(UP, ethan);
						}
						else pojedynek->wybierz_akcje->move(UP);
					}
					else if (zdarzenie.key.code == Keyboard::Down)
					{
						if (pojedynek->wybierz_akcje->getRodzaj() == Lista_pokemon)
							pokemon_window->move_kursor(DOWN);
						else if (pojedynek->wybierz_akcje->getRodzaj() == Lista_przedmiotow)
						{
							plecak_window->move_kursor(DOWN, ethan);
						}
						else pojedynek->wybierz_akcje->move(DOWN);
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
						case Lista_przedmiotow:
							menu_plecak = false;
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
							else if (pojedynek->wybierz_akcje->getRodzaj() == Lista_przedmiotow) menu_plecak = true;
							break;
						case Walka:
							if (!walka_zNPC)
								pojedynek->update(m_Window, ethan);
							else 
								pojedynek->update(m_Window, ethan, gym_leader);
							break;
						case Lista_przedmiotow:
							if (typeid(*ethan.plecak[plecak_window->getIndeks()]) == typeid(PokeBall) && walka_zNPC == false)
							{
								ethan.plecak[plecak_window->getIndeks()]->zurzyj();
								pojedynek->lapPrzeciwnika(ethan, ethan.plecak[plecak_window->getIndeks()]->lap());
								if(ethan.sprawdz_plecak())
									plecak_window->zresetuj_kursor();
							}
							else if (typeid(*ethan.plecak[plecak_window->getIndeks()]) == typeid(Potion))
							{
								ethan.plecak[plecak_window->getIndeks()]->zurzyj();
								pojedynek->uleczSojusznika(ethan.plecak[plecak_window->getIndeks()]->lap());
								if (ethan.sprawdz_plecak())
									plecak_window->zresetuj_kursor();
							}
							menu_plecak = false;
							pojedynek->wybierz_akcje->move(BACK);
							break;
						case Lista_pokemon:
							int i = pokemon_window->swap();
							if (ethan.getPokemon(i)->getC_HP() > 0)
							{
								pojedynek->setSojusznik(ethan.getPokemon(i));
								menu_pokemon = false;
								pojedynek->wybierz_akcje->move(BACK);
							}
							break;
						}
						if (pojedynek->wybierz_akcje->getWyjdz_z_walki() == true)
						{
							vs_poke_battle_music.stop();
							if (walka_zNPC)
							{
								delete(gym_leader);
								gym_music.play();
							}
							else
								route_music.play();
							delete pojedynek;
							walka = false;
							walka_zNPC = false;
						}
						break;
					}
					break;
				}
				default: break;
				}
			else
			{
				vs_poke_battle_music.stop();
				if (walka_zNPC)
				{
					walka_z_bossem++;
					delete(gym_leader);
					gym_music.play();
				}
				else
					route_music.play();
				delete pojedynek;
				walka = false;
				walka_zNPC = false;
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
					if (menu_pokemon)
						pokemon_window->move_kursor(UP);
					else if (menu_plecak)
					{
						plecak_window->move_kursor(UP, ethan);
					}
					else opcje->move(UP);
				}
				else if (zdarzenie.key.code == Keyboard::X && menu_pokemon)
				{
					if (pokemon_window->getZaznaczenie() != -1)
					{
						pokemon_window->setZaznaczenie();
					}
					else menu_pokemon = false;
				}
				else if (zdarzenie.key.code == Keyboard::X && menu_plecak)
				{
					menu_plecak = false;
				}
				else if (zdarzenie.key.code == Keyboard::Down)
				{
					if (menu_pokemon)
						pokemon_window->move_kursor(DOWN);
					else if (menu_plecak)
					{
						plecak_window->move_kursor(DOWN, ethan);
					}
					else
					opcje->move(DOWN);
				}
				else if (zdarzenie.key.code == Keyboard::Z && menu_pokemon)
				{
					if (pokemon_window->getZaznaczenie() == -1)
					{
						pokemon_window->zaznacz();
					}
					else
					{
						pokemon_window->swap(ethan);
					}
				}
				else if (zdarzenie.key.code == Keyboard::Z && opcje->getPozycja() == 0)
				{
					menu_pokemon = true;
				}
				else if (zdarzenie.key.code == Keyboard::Z && opcje->getPozycja() == 1)
				{
					menu_plecak = true;
				}
				else if (zdarzenie.key.code == Keyboard::Z && opcje->getPozycja() == 2)
				{
					cout << "SAVE TU" << endl;
				}
				else if (zdarzenie.key.code == Keyboard::Z && opcje->getPozycja() == 3)
				{
					m_Window.close();
				}
				else if (zdarzenie.key.code == Keyboard::Tab && !menu_pokemon)
				{
					delete opcje;
					menu_is_open = false;
				}
				else if (zdarzenie.key.code == Keyboard::X && !menu_pokemon)
				{
					delete opcje;
					menu_is_open = false;
				}
			}
			default: break;
		}
		else if (shop_is_open)
			switch (zdarzenie.type)
			{
			case Event::Closed:
				m_Window.close();
				break;
			case Event::KeyPressed:
			{
				if (zdarzenie.key.code == Keyboard::X)
				{
					if (buying_is_open)
					{
						buying_is_open = false;
					}
					else if (menu_plecak)
					{
						menu_plecak = false;
					}
					else
					{
						delete shop;
						delete shop_buy;
						shop_is_open = false;
					}
				}
				else if (zdarzenie.key.code == Keyboard::Down)
				{
					if (buying_is_open)
						shop_buy->move(DOWN);
					else if(menu_plecak)
						plecak_window->move_kursor(DOWN, ethan);
					else
						shop->move(DOWN);
				}
				else if (zdarzenie.key.code == Keyboard::Up)
				{
					if (buying_is_open)
						shop_buy->move(UP);
					else if(menu_plecak)
						plecak_window->move_kursor(UP, ethan);
					else
						shop->move(UP);
				}
				else if (zdarzenie.key.code == Keyboard::Z && shop->getPozycja() == 0 && !buying_is_open && !menu_plecak)
				{
					shop_buy->im_buying();
					buying_is_open = true;
				}
				else if (zdarzenie.key.code == Keyboard::Z && shop->getPozycja() == 1 && !buying_is_open && !menu_plecak)
				{
					menu_plecak = true;
				}
				else if (zdarzenie.key.code == Keyboard::Z && shop_buy->getPozycja() == 0 && buying_is_open)
				{
					if (ethan.getGold() - 200 >= 0)
					{
						ethan.setGold(ethan.getGold() - 200);
						shop->ustaw_pieniadze(ethan.getGold(),ethan.getX(), ethan.getY());
						ethan.dodaj_przedmiot(new PokeBall(1));
					}
				}
				else if (zdarzenie.key.code == Keyboard::Z && shop_buy->getPozycja() == 1 && buying_is_open)
				{
					if (ethan.getGold() - 100 >= 0)
					{
						ethan.setGold(ethan.getGold() - 100);
						shop->ustaw_pieniadze(ethan.getGold(), ethan.getX(), ethan.getY());
						ethan.dodaj_przedmiot(new Potion(1));
					}
				}
				else if (zdarzenie.key.code == Keyboard::Z && menu_plecak)
				{
					if (typeid(*ethan.plecak[plecak_window->getIndeks()]) == typeid(PokeBall))
					{
						ethan.plecak[plecak_window->getIndeks()]->zurzyj();
						ethan.setGold(ethan.getGold() + 100);
						shop->ustaw_pieniadze(ethan.getGold(), ethan.getX(), ethan.getY());
					}
					else if (typeid(*ethan.plecak[plecak_window->getIndeks()]) == typeid(Potion))
					{
						ethan.plecak[plecak_window->getIndeks()]->zurzyj();
						ethan.setGold(ethan.getGold() + 50);
						shop->ustaw_pieniadze(ethan.getGold(), ethan.getX(), ethan.getY());
					}
					ethan.sprawdz_plecak();
				}
				else if (zdarzenie.key.code == Keyboard::Z && shop->getPozycja() == 2)
				{
					delete shop_buy;
					delete shop;
					shop_is_open = false;
				}
			}
			break;			
		}
	}
}