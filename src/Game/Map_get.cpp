/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Map_get
*/

#include "Map.hpp"

std::vector<irr::scene::IMeshSceneNode *> *Map::getNodesMap() { return &_n; }

std::vector<std::string> *Map::getStringMap() { return &_map; }

int Map::getX() const { return _x; }

int Map::getY() const { return _y; }