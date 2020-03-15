/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Saver_save
*/

#include "Bomberman.hpp"
#include "Game.hpp"
#include "Item.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Utils.hpp"

void Saver::SavePlayers()
{
	Game *game = Game::getInstance();
	std::vector<Player *> *players = game->getPlayers();

	for (int i = 0; i < players->size(); i++) {
		Player *player = players->at(i);
		_tree->add("bomberman.game.players.player", "");
		// _tree->put("bomberman.game.players.player.posX",
		// player->getNode()->getPosition().X);
		// _tree->put("bomberman.game.players.player.posY",
		// player->getNode()->getPosition().Y);
		_tree->put(
		    "bomberman.game.players.player.dead", player->isDead());
		_tree->put(
		    "bomberman.game.players.player.speed", player->getSpeed());
		_tree->put(
		    "bomberman.game.players.player.power", player->getPower());
		_tree->put("bomberman.game.players.player.maxBomb",
		    player->getNbMaxBomb());
	}
}

void Saver::SaveMap()
{
	Game *game = Game::getInstance();
	std::vector<std::string> *map = game->getMap()->getStringMap();

	_tree->add("bomberman.map.size.X", game->getMap()->getX());
	_tree->add("bomberman.map.size.Y", game->getMap()->getY());
	for (int j = 0; j < map->size(); j++)
		_tree->add("bomberman.map.map.row", map->at(j));
}

void Saver::SaveGame()
{
	Bomberman *b = Bomberman::getInstance();
	Game *game = Game::getInstance();
	std::vector<IItem *> *items = game->getItems();

	if (_tree == nullptr)
		_tree = new pt::ptree();
	_tree->add("bomberman.settings.volume", b->getVolume());
	this->SavePlayers();
	for (int i = 0; i < items->size(); i++) {
		IItem *item = items->at(i);
		_tree->add("bomberman.game.items.item.type", item->getType());
	}
	this->SaveMap();
	if (!_filename.empty())
		pt::write_xml(_filename, *_tree);
}