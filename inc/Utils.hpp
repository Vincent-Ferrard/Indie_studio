/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include "Menu.hpp"
#include "irrlicht.h"

struct AppContext
{
	irr::IrrlichtDevice *device;
	Menu *menu;
};

bool MenuEV(const irr::SEvent &e);
bool GameEV(const irr::SEvent &e);
void checkEndGame();
void clear();

#endif /* !UTILS_HPP_ */