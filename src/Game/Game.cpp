/*
** EPITECH PROJECT, 2019
** indie (workspace)
** File description:
** Game.cpp
*/

#include "Game.hpp"


#include <iostream>

Game::Game() {}

Game *Game::_instance = nullptr;

Game::~Game()
{
	for (unsigned int i = 0; i < _players.size(); i++) delete _players[i];
	delete _map;
	_players.clear();
}

Game *Game::getInstance()
{
	if (_instance == nullptr)
		_instance = new Game();
	return (_instance);
}

void Game::loadMap()
{
	LibManager *irr = LibManager::getInstance();
	irr::scene::ISceneManager *smgr = irr->getSmgr();
	irr::video::IVideoDriver *driver = irr->getDriver();

	irr::scene::ISceneNode *skybox = smgr->addSkyBoxSceneNode(
	    driver->getTexture("./assets/irrlicht2_up.jpg"),
	    driver->getTexture("./assets/irrlicht2_dn.jpg"),
	    driver->getTexture("./assets/irrlicht2_lf.jpg"),
	    driver->getTexture("./assets/irrlicht2_rt.jpg"),
	    driver->getTexture("./assets/irrlicht2_ft.jpg"),
	    driver->getTexture("./assets/irrlicht2_bk.jpg"));

	_players.push_back(new Player("./assets/dwarf1.jpg", "./assets/dwarf.x",
	    irr::core::vector3df(100, 1000, 1100)));
	_players[0]->setControllers(irr::KEY_KEY_Z, irr::KEY_KEY_S,
	    irr::KEY_KEY_Q, irr::KEY_KEY_D, irr::KEY_SPACE);
	_players.push_back(new Player("./assets/dwarf2.jpg", "./assets/dwarf.x",
	    irr::core::vector3df(100, 1000, 100)));
	_players[1]->setControllers(irr::KEY_UP, irr::KEY_DOWN, irr::KEY_LEFT,
	    irr::KEY_RIGHT, irr::KEY_RETURN);

	// Set Camera
	_camera[0] =
	    smgr->addCameraSceneNode(0, irr::core::vector3df(400, 1680, 550),
		irr::core::vector3df(920, 200, 550));
	_camera[1] = smgr->addCameraSceneNode(0,
	    irr::core::vector3df(
		(*getPlayers())[0]->getNode()->getPosition().X - 200, 400,
		(*getPlayers())[0]->getNode()->getPosition().Z),
	    irr::core::vector3df(
		(*getPlayers())[0]->getNode()->getPosition().X + 100, 0,
		(*getPlayers())[0]->getNode()->getPosition().Z));
	_camera[2] = smgr->addCameraSceneNode(0,
	    irr::core::vector3df(
		(*getPlayers())[1]->getNode()->getPosition().X - 200, 400,
		(*getPlayers())[1]->getNode()->getPosition().Z),
	    irr::core::vector3df(
		(*getPlayers())[1]->getNode()->getPosition().X + 100, 0,
		(*getPlayers())[1]->getNode()->getPosition().Z));
	smgr->setActiveCamera(_camera[0]);
	this->_map = new Map(19, 11);
}