/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Saver_load
*/

#include "Bomberman.hpp"
#include "Game.hpp"
#include "Item.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Saver.hpp"
#include "Utils.hpp"

Map *Saver::LoadMap()
{
	Map *m = nullptr;
	std::vector<std::string> *map = new std::vector<std::string>();

	m = new Map(_tree->get<int>("bomberman.map.size.X"),
	    _tree->get<int>("bomberman.map.size.Y"));
	BOOST_FOREACH (
	    pt::ptree::value_type &v, _tree->get_child("bomberman.map.map")) {
		map->push_back(v.second.data());
	}
	m->importMap(map);
	return (m);
}

std::vector<Player *> *Saver::LoadPlayers()
{
	std::vector<Player *> *players = new std::vector<Player *>();

	BOOST_FOREACH (pt::ptree::value_type &v,
	    _tree->get_child("bomberman.game.players")) {
		Player *player = new Player("./assets/dwarf.jpg",
		    "./assets/dwarf.x", irr::core::vector3df(100, 1000, 100));
		players->push_back(player);
	}
	return (players);
}

void Saver::LoadGame()
{
	Bomberman *b = Bomberman::getInstance();
	Game *g = Game::getInstance();
	std::vector<Player *> *players = nullptr;
	Map *m = nullptr;

	std::cout << "Loading Game..." << std::endl;
	if (_tree == nullptr)
		_tree = new pt::ptree();
	pt::read_xml(_filename, *_tree);
	b->setVolume(_tree->get<int>("bomberman.settings.volume"));
	players = this->LoadPlayers();
	m = this->LoadMap();
	EventListener *e = (EventListener *)LibManager::getInstance()
			       ->getDevice()
			       ->getEventReceiver();
	e->setFunction(&GameEV);
	Menu::getInstance()->_game = true;
	g->setMap(m);
	g->setPlayers(players);
	g->loadMap();
	g->getPlayers()->clear();
	g->setPlayers(players);
}