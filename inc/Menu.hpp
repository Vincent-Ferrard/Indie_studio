/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "irrlicht.h"

class Menu {
        private:
                void drawMain(irr::gui::IGUIEnvironment *gui,
                        irr::video::IVideoDriver *driver);
                void drawSettings(irr::gui::IGUIEnvironment *gui,
                        irr::video::IVideoDriver *driver);
		Menu();
                static Menu *_instance;
                int menu;
                int base;
	public:
                static Menu *getInstance();
                int getMenu();
                void setMenu(int slide);
                void setBase(int slide);
                int getBase();
                void DoAction();
                void initSetting();
                void initMain();
                void draw(
                        irr::gui::IGUIEnvironment *gui,
                        irr::video::IVideoDriver *driver);
                irr::core::position2d<irr::s32> _bpos;
                bool _settings;
                bool _game;
                size_t _sel;
};

bool MenuESetting(const irr::SEvent &e);

#endif /* !MENU_HPP_ */