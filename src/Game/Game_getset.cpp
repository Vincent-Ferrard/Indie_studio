/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Game_getset
*/

#include "Game.hpp"

irr::scene::IAnimatedMeshSceneNode *Game::getPlayer() const
{
	return (_players[0]->getNode());
}

std::vector<Player *> *Game::getPlayers() { return (&_players); }

Map *Game::getMap() const { return (_map); }

void Game::setMap(Map *map)
{
	if (_map)
		delete _map;
	_map = map;
}

void Game::setPlayers(std::vector<Player *> *p)
{
	for (int i = 0; i < p->size(); i++) _players.push_back(p->at(i));
}