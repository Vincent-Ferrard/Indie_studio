/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Bomberman_run
*/

#include "Bomberman.hpp"

void Bomberman::run(EventListener *listener)
{
	irr::IrrlichtDevice *device = _irr->getDevice();
	irr::video::IVideoDriver *driver = _irr->getDriver();

	srand(time(NULL));
	listener->setFunction(&MenuEV);
	while (device->run() && _irr->getDriver()) {
		if (!device->isWindowActive())
			continue;
		driver->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
		_irr->getGui()->drawAll();
		_irr->getSmgr()->drawAll();

		if (!_menu->_game)
			_menu->draw(_irr->getGui(), _irr->getDriver());

		if (_menu->_game) {
			std::vector<Player *> *players = _game->getPlayers();
			std::vector<IItem *> *items = _game->getItems();

			checkEndGame();
			for (unsigned int i = 0; i < players->size(); i++) {
				(*players)[i]->move();
				int k = 0;
				for (auto j = items->begin(); j < items->end();
				     j++, k++)
					if (!(*players)[i]->isDead() &&
					    (*players)[i]
						    ->getNode()
						    ->getPosition()
						    .X >=
						(*items)[k]
							->getNode()
							->getPosition()
							.X -
						    50 &&
					    (*players)[i]
						    ->getNode()
						    ->getPosition()
						    .X <=
						(*items)[k]
							->getNode()
							->getPosition()
							.X +
						    50 &&
					    (*players)[i]
						    ->getNode()
						    ->getPosition()
						    .Z >=
						(*items)[k]
							->getNode()
							->getPosition()
							.Z -
						    50 &&
					    (*players)[i]
						    ->getNode()
						    ->getPosition()
						    .Z <=
						(*items)[k]
							->getNode()
							->getPosition()
							.Z +
						    50) {
						(*items)[k]->action(
						    (*players)[i]);
						delete (*items)[k];
						items->erase(j);
					}
			}
			if (Game::getInstance()->screenIsSplit()) {
				LibManager::getInstance()
				    ->getSmgr()
				    ->setActiveCamera(
					Game::getInstance()->getCamera(1));
				LibManager::getInstance()
				    ->getDriver()
				    ->setViewPort(irr::core::rect<irr::s32>(
					0, 0, 1080, 720 / 2));
				LibManager::getInstance()->getSmgr()->drawAll();
				LibManager::getInstance()
				    ->getSmgr()
				    ->setActiveCamera(
					Game::getInstance()->getCamera(2));
				LibManager::getInstance()
				    ->getDriver()
				    ->setViewPort(irr::core::rect<irr::s32>(
					0, 720 / 2, 1080, 720));
				LibManager::getInstance()->getSmgr()->drawAll();
			}
		}
		driver->endScene();
	}
	device->drop();
}