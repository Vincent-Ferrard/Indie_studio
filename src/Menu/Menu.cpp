/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Menu
*/

#include "Menu.hpp"

#include "Bomberman.hpp"
#include "EventListener.hpp"
#include "LibManager.hpp"
#include "Settings.hpp"
#include "Utils.hpp"
#include "irrlicht.h"

Menu::Menu() : _settings(false), _game(false), _bpos(445, 280)
{
	this->menu = 0;
	this->base = 0;
}

Menu *Menu::_instance = nullptr;

Menu *Menu::getInstance()
{
	if (_instance == nullptr)
		_instance = new Menu();
	return (_instance);
}

void Menu::initSetting()
{
	irr::IrrlichtDevice *d = LibManager::getInstance()->getDevice();
	_settings = true;
	_bpos.Y = 200;
	_bpos.X = 200;
	_sel = 0;
	EventListener *e = (EventListener *)d->getEventReceiver();
	e->setFunction(MenuESetting);
}

void Menu::initMain()
{
	irr::IrrlichtDevice *d = LibManager::getInstance()->getDevice();
	_settings = false;
	_bpos.X = 445;
	_bpos.Y = 280;
	_sel = 0;
	EventListener *e = (EventListener *)d->getEventReceiver();
	e->setFunction(MenuEV);
}

int Menu::getMenu() { return (this->menu); }

void Menu::setMenu(int slide) { this->menu = slide; }

void Menu::setBase(int slide) { this->base = slide; }

int Menu::getBase() { return (this->base); }
