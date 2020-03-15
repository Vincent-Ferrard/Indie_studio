/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Menu_EL
*/

#include "Bomberman.hpp"
#include "EventListener.hpp"
#include "LibManager.hpp"
#include "Menu.hpp"
#include "Settings.hpp"
#include "Utils.hpp"
#include "irrlicht.h"

// bool MenuEV(const irr::SEvent &e)
// {
// 	Menu *menu = Menu::getInstance();

// 	if (e.EventType == irr::EET_KEY_INPUT_EVENT) {
// 		if (e.KeyInput.Key == irr::KEY_DOWN &&
// 		    menu->_bpos.Y + 60 <= 500 && !e.KeyInput.PressedDown) {
// 			menu->_bpos.Y += 60;
// 			menu->_sel += 1;
// 		}
// 		if (e.KeyInput.Key == irr::KEY_UP &&
// 		    menu->_bpos.Y - 60 >= 280 && !e.KeyInput.PressedDown) {
// 			menu->_bpos.Y -= 60;
// 			menu->_sel -= 1;
// 		}
// 		if (e.KeyInput.Key == irr::KEY_RETURN) {
// 			menu->DoAction();
// 		}
// 	}
// 	return (false);
// }

/*
	menu == 0; -> title screen
			1; -> main menu
			2; -> load new game
			3; -> pause menu
			4; -> 1 or 2 player menu
			5; -> option menu (how to play)
			6; -> end game menu

			7;; -> continu (?)

*/

bool MenuEV(const irr::SEvent &e)
{
	Menu *menu = Menu::getInstance();

	if (menu->_game)
		return (GameEV(e));
	if (e.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (menu->getMenu() == 1) {

			if (e.KeyInput.Key == irr::KEY_DOWN &&
			    menu->_bpos.Y + 60 <= 500 &&
			    !e.KeyInput.PressedDown) {
				menu->_bpos.Y += 60;
				menu->_sel += 1;
				menu->setBase(menu->getBase() + 1);
				if (menu->getBase() > 3)
					menu->setBase(0);
			}

			if (e.KeyInput.Key == irr::KEY_UP &&
			    menu->_bpos.Y - 60 >= 280 &&
			    !e.KeyInput.PressedDown) {
				menu->_bpos.Y -= 60;
				menu->_sel -= 1;
				menu->setBase(menu->getBase() - 1);
				if (menu->getBase() < 0)
					menu->setBase(3);
			}

			// new game
			if (e.KeyInput.Key == irr::KEY_RETURN &&
			    menu->_bpos.Y == 280 && e.KeyInput.PressedDown) {
				menu->setMenu(2);
			}

			// option
			if ((e.KeyInput.Key == irr::KEY_RETURN &&
				!e.KeyInput.PressedDown) &&
			    menu->getBase() == 2) {
				menu->setMenu(5);
			}

			// continue
			// if (e.KeyInput.Key == irr::KEY_RETURN &&
			// menu->_bpos.Y == 340) {
			// 	Saver::getInstance()->LoadGame();
			// }

			// exit
			if (e.KeyInput.Key == irr::KEY_RETURN &&
			    menu->_bpos.Y == 460)
				LibManager::getInstance()
				    ->getDevice()
				    ->closeDevice();

			// escape
			if (e.KeyInput.Key == irr::KEY_ESCAPE &&
			    !e.KeyInput.PressedDown) {
				menu->setMenu(0);
				menu->setBase(0);
			}
		} else if (menu->getMenu() == 0) {
			if (e.KeyInput.Key == irr::KEY_RETURN)
				menu->setMenu(1);
			if (e.KeyInput.Key == irr::KEY_ESCAPE)
				LibManager::getInstance()
				    ->getDevice()
				    ->closeDevice();
		} else if (menu->getMenu() == 2) {
			if (e.KeyInput.Key == irr::KEY_ESCAPE &&
			    !e.KeyInput.PressedDown) {
				menu->setMenu(3);
			}
		} else if (menu->getMenu() == 3) {

			if (e.KeyInput.Key == irr::KEY_ESCAPE &&
			    !e.KeyInput.PressedDown) {
				menu->_game = true;
			}

			// Exit
			if ((e.KeyInput.Key == irr::KEY_RETURN &&
				!e.KeyInput.PressedDown) &&
			    menu->getBase() == 2) {
				menu->setMenu(1);
				clear();
				for (unsigned int i = 0;
				     i <
				     Game::getInstance()->getPlayers()->size();
				     i++)
					delete (*Game::getInstance()
						     ->getPlayers())[i];
				Game::getInstance()->getPlayers()->clear();
				menu->setBase(0);
			}

			// Resume
			if ((e.KeyInput.Key == irr::KEY_RETURN &&
				!e.KeyInput.PressedDown) &&
			    menu->getBase() == 0)
				menu->_game = true;

			// Save
			if ((e.KeyInput.Key == irr::KEY_RETURN &&
				!e.KeyInput.PressedDown) &&
			    menu->getBase() == 1) {
				// Saver::getInstance()->SaveGame();
			}

			if (e.KeyInput.Key == irr::KEY_DOWN &&
			    !e.KeyInput.PressedDown) {
				menu->setBase(menu->getBase() + 1);
				if (menu->getBase() > 2)
					menu->setBase(0);
			}

			if (e.KeyInput.Key == irr::KEY_UP &&
			    !e.KeyInput.PressedDown) {
				menu->setBase(menu->getBase() - 1);
				if (menu->getBase() < 0)
					menu->setBase(2);
			}
		} else if (menu->getMenu() == 5) {
			if ((e.KeyInput.Key == irr::KEY_RETURN ||
				e.KeyInput.Key == irr::KEY_ESCAPE) &&
			    !e.KeyInput.PressedDown) {
				menu->setMenu(1);
			}
		}
	}
	return (false);
}

bool MenuESetting(const irr::SEvent &e)
{
	Menu *menu = Menu::getInstance();
	Settings *s = Settings::getInstance();

	if (e.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (e.KeyInput.Key == irr::KEY_TAB && !e.KeyInput.PressedDown) {
			if (menu->_bpos.Y == 600) {
				menu->_bpos.Y -= 400;
				menu->_bpos.X += 150;
				menu->_sel = 0;
			} else {
				menu->_bpos.Y += 400;
				menu->_bpos.X -= 150;
				menu->_sel = 1;
			}
		}
		if (e.KeyInput.Key == irr::KEY_UP && !e.KeyInput.PressedDown) {
			s->setVolume(s->getVolume() + 10);
		}
		if (e.KeyInput.Key == irr::KEY_DOWN &&
		    !e.KeyInput.PressedDown) {
			s->setVolume(s->getVolume() - 10);
		}
		if (e.KeyInput.Key == irr::KEY_RETURN && menu->_bpos.Y == 600) {
			menu->initMain();
		}
	}
	return (false);
}