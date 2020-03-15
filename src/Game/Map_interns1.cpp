/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Map_interns1
*/

#include "Game.hpp"
#include "Map.hpp"

std::string Map::fullLine(int x)
{
	std::string line;

	for (int i = 0; i <= x; i++) line.push_back('#');
	line.push_back('#');
	return line;
}

std::string Map::caseLine(int x)
{
	std::string line;

	line.push_back('#');
	for (int i = 1; i <= x; i++) {
		if (i % 2 == 0)
			line.push_back('#');
		else
			line.push_back(' ');
	}
	line.push_back('#');
	return line;
}

std::string Map::voidLine(int x)
{
	std::string line;

	line.push_back('#');
	for (int i = 1; i <= x; i++) line.push_back(' ');
	line.push_back('#');
	return line;
}

void Map::creatMap()
{
	if (_x % 2 == 0 || _y % 2 == 0) {
		std::cerr << "Map sizes should be odd numbers" << std::endl;
		exit(84);
	}
	_map.push_back(fullLine(_x));
	for (int i = 1; i <= _y; i++) {
		if (i % 2 == 0)
			_map.push_back(caseLine(_x));
		else
			_map.push_back(voidLine(_x));
	}
	_map.push_back(fullLine(_x));
}

std::vector<int> Map::nbrvoidLine(int y)
{
	std::vector<int> n;

	n.push_back(0);
	n.push_back(0);
	n.push_back(0);
	for (unsigned int x = 0; x <= _map[y].size(); x++) {
		if (_map[y][x] == ' ')
			n[0] = n[0] + 1;
		else if (_map[y][x] == 'B')
			n[1] = n[1] + 1;
	}
	n[2] = n[0] + n[1];
	return n;
}