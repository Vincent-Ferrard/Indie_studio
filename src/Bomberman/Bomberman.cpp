/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Bomberman
*/

#include "Bomberman.hpp"

#include <iostream>

Bomberman::Bomberman()
	: _irr(nullptr), _ev(nullptr), _menu(Menu::getInstance()),
	  _game(Game::getInstance())
{}

Bomberman::~Bomberman()
{
	if (_irr)
		delete _irr;
	if (_game)
		delete _game;
}

Bomberman *Bomberman::_instance = nullptr;

void Bomberman::init(AppContext &context, EventListener *listener)
{
	_irr = LibManager::getInstance();
	_settings = Settings::getInstance();
	_irr->init();
	context.device = _irr->getDevice();
	_irr->setEventListener(listener);
}

void clear()
{
	LibManager *irr = LibManager::getInstance();

	irr->getGui()->clear();
	irr->getSmgr()->clear();
}