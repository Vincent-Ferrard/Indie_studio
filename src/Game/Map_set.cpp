/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Map_set
*/

#include "Map.hpp"

void Map::setPhysicalMap()
{
	for (int y = 0; y < _map.size(); y++) {
		for (int x = 0; x < _map[y].size(); x++) {
			if (_map[y][x] == 'B')
				addPhysicalBox(x * 100, 0, y * 100);
			else if (_map[y][x] == '#')
				addPhysicalWall(x * 100, 0, y * 100);
		}
	}
}

void Map::setBox() // max: 71% - min: 29%
{
	for (unsigned int y = 1; y < this->_map.size(); y++) {
		for (unsigned int x = 1; x <= this->_map[y].size(); x++)
			thereIsBox(x, y);
	}
}

void Map::setPlayer()
{
	_map[1][1] = '1';
	_map[1][2] = 'X';
	_map[2][1] = 'X';
	_map[1][_x] = '2';
	_map[1][_x - 1] = 'X';
	_map[2][_x] = 'X';
	_map[_y][1] = '3';
	_map[_y - 1][1] = 'X';
	_map[_y][2] = 'X';
	_map[_y][_x] = '4';
	_map[_y - 1][_x] = 'X';
	_map[_y][_x - 1] = 'X';
}

void Map::importMap(std::vector<std::string> *map)
{
	_x = map->size();
	_y = map->at(0).size();
	_map.clear();
	for (int i = 0; i < map->size(); i++) _map.push_back(map->at(i));
}