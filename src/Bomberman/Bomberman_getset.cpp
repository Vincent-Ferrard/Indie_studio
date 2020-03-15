/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Bomberman_get
*/

#include "Bomberman.hpp"

Bomberman *Bomberman::getInstance()
{
	if (_instance == nullptr)
		_instance = new Bomberman();
	return (_instance);
}

int Bomberman::getVolume() const { return _settings->getVolume(); }

Menu *Bomberman::getMenu() const { return (_menu); }

Game *Bomberman::getGame() const { return (_game); }

void Bomberman::setVolume(int vol) { _settings->setVolume(vol); }