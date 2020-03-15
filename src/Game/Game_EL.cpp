/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Game_EL
*/

#include "Game.hpp"

bool GameEV(const irr::SEvent &e)
{
	Game *game = Game::getInstance();

	if (game->screenIsSplit()) {
		game->getCamera(1)->setPosition(irr::core::vector3df(
		    (*game->getPlayers())[0]->getNode()->getPosition().X - 200,
		    400, (*game->getPlayers())[0]->getNode()->getPosition().Z));
		game->getCamera(1)->setTarget(irr::core::vector3df(
		    (*game->getPlayers())[0]->getNode()->getPosition().X + 50,
		    (*game->getPlayers())[0]->getNode()->getPosition().Y,
		    (*game->getPlayers())[0]->getNode()->getPosition().Z));
		game->getCamera(2)->setPosition(irr::core::vector3df(
		    (*game->getPlayers())[1]->getNode()->getPosition().X - 200,
		    400, (*game->getPlayers())[1]->getNode()->getPosition().Z));
		game->getCamera(2)->setTarget(irr::core::vector3df(
		    (*game->getPlayers())[1]->getNode()->getPosition().X + 100,
		    (*game->getPlayers())[1]->getNode()->getPosition().Y,
		    (*game->getPlayers())[1]->getNode()->getPosition().Z));
	}

	if (e.EventType == irr::EET_KEY_INPUT_EVENT) {
		std::vector<Player *> *players = game->getPlayers();
		for (int i = 0; i < players->size(); i++)
			(*players)[i]->handleInputEvents(e);
	}
	if (e.EventType == irr::EET_KEY_INPUT_EVENT) {
		switch (e.KeyInput.Key) {
			case irr::KEY_ESCAPE:
				if (!e.KeyInput.PressedDown) {
					LibManager::getInstance()
					    ->getDriver()
					    ->setViewPort(
						irr::core::rect<irr::s32>(
						    0, 0, 1080, 720));
					Menu::getInstance()->_game = false;
					EventListener *e =
					    (EventListener *)
						LibManager::getInstance()
						    ->getDevice()
						    ->getEventReceiver();
					e->setFunction(&MenuEV);
				}
				return (true);
				/*if (!e.KeyInput.PressedDown) {
					clear();
					Saver::getInstance()->SaveGame();
					for (unsigned int i = 0;
					     i < game->getPlayers()->size();
					     i++)
						delete (*game->getPlayers())[i];
					game->getPlayers()->clear();
					Menu::getInstance()->_game = false;
					EventListener *e =
					    (EventListener *)
						LibManager::getInstance()
						    ->getDevice()
						    ->getEventReceiver();
					e->setFunction(MenuEV);
				}
				return (true);*/
			case irr::KEY_KEY_C:
				if (!e.KeyInput.PressedDown)
					if (LibManager::getInstance()
						->getSmgr()
						->getActiveCamera() ==
					    game->getCamera(0)) {
						game->setSplitScreen(true);
					} else {
						game->setSplitScreen(false);
						LibManager::getInstance()
						    ->getSmgr()
						    ->setActiveCamera(
							game->getCamera(0));
						LibManager::getInstance()
						    ->getDriver()
						    ->setViewPort(
							irr::core::rect<
							    irr::s32>(
							    0, 0, 1080, 720));
					}
				return (true);
		}
	}
	return (false);
}

void checkEndGame()
{
	std::vector<Player *> *players = Game::getInstance()->getPlayers();
	int nbDead = 0;
	EventListener *e = (EventListener *)LibManager::getInstance()
			       ->getDevice()
			       ->getEventReceiver();

	for (unsigned int i = 0; i < players->size(); i++)
		if ((*players)[i]->isDead())
			nbDead++;
	if (players->size() - nbDead <= 1) {
		clear();
		for (unsigned int i = 0; i < players->size(); i++)
			delete (*players)[i];
		// Saver::getInstance()->SaveGame();
		Menu::getInstance()->_game = false;
		Menu::getInstance()->setMenu(1);
		e->setFunction(MenuEV);
		players->clear();
		Game::getInstance()->setSplitScreen(false);
		LibManager::getInstance()->getDriver()->setViewPort(
		    irr::core::rect<irr::s32>(0, 0, 1080, 720));
	}
}