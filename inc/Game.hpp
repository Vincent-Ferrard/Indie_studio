/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Item.hpp"
#include "LibManager.hpp"
#include "Map.hpp"
#include "Player.hpp"

#include <irrlicht.h>
#include <string>
#include <vector>

class Game {
      private:
	Map *_map;
	std::vector<Player *> _players;
	std::vector<IItem *> _items;
	irr::scene::ICameraSceneNode *_camera[3] = {0, 0, 0};
	bool _splitScreen = false;
	Game();
	static Game *_instance;

      public:
	~Game();
	static Game *getInstance();
	void loadMap();
	bool saveMap(std::string path);
	irr::scene::IAnimatedMeshSceneNode *getPlayer() const;
	std::vector<Player *> *getPlayers();
	std::vector<IItem *> *getItems() { return (&_items); };
	Map *getMap() const;
	void setMap(Map *map);
	void setPlayers(std::vector<Player *> *p);
	irr::scene::ICameraSceneNode *getCamera(int id) const { return (_camera[id]); };
	bool screenIsSplit() const { return (_splitScreen); };
	void setSplitScreen(bool value) { _splitScreen = value; };
};

#endif /* !GAME_HPP_ */