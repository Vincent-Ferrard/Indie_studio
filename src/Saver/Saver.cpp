/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Saver
*/


#include "Bomberman.hpp"
#include "Game.hpp"
#include "Item.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Utils.hpp"

Saver::Saver() : _filename("save.xml"), _tree(new pt::ptree())
{
	_tree->put("bomberman.name", "Bomberman");
}

Saver *Saver::_instance = nullptr;

pt::ptree *Saver::getTree() const { return _tree; }

void Saver::setFilename(const std::string &filename) { _filename = filename; }

Saver *Saver::getInstance()
{
	if (_instance == nullptr)
		_instance = new Saver();
	return _instance;
}