/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Menu_DoAction
*/

#include "Bomberman.hpp"
#include "EventListener.hpp"
#include "LibManager.hpp"
#include "Menu.hpp"
#include "Utils.hpp"
#include "irrlicht.h"

void Menu::DoAction()
{
	irr::IrrlichtDevice *d = LibManager::getInstance()->getDevice();
	Bomberman *b = Bomberman::getInstance();
	Game *game = nullptr;
	EventListener *e = (EventListener *)d->getEventReceiver();
	// Saver *saver = Saver::getInstance();

	switch (_sel) {
		case 0:
			clear();
			game = Game::getInstance();
			game->getPlayers()->clear();
			game->getItems()->clear();
			game->loadMap();
			_game = true;
			e->setFunction(GameEV);
			break;
		case 1:
			// Saver::getInstance()->LoadGame();
			break;
		case 2:
			_settings = true;
			initSetting();
			break;
		case 3:
			d->closeDevice();
			break;
		default:
			break;
	}
}