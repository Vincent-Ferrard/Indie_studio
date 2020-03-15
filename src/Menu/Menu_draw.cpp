/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Menu_draw
*/

#include "Game.hpp"
#include "Menu.hpp"
#include "Utils.hpp"
#include "irrlicht.h"

void Menu::draw(
    irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver)
{
	if (_settings == true) {
		drawSettings(gui, driver);
		return;
	}
	drawMain(gui, driver);
}

void Menu::drawSettings(
    irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver)
{
	irr::video::ITexture *bg = driver->getTexture("./assets/settings.jpg");
	driver->draw2DImage(bg, irr::core::position2d<irr::s32>(0, 0),
	    irr::core::rect<irr::s32>(0, 0, 1082, 722), 0,
	    irr::video::SColor(255, 255, 255, 255), true);
	irr::video::ITexture *sel = driver->getTexture("./assets/bomb50.png");
	driver->draw2DImage(sel, _bpos, irr::core::rect<irr::s32>(0, 0, 43, 49),
	    0, irr::video::SColor(255, 255, 255, 255), true);
}

static void drawMenu0(irr::video::IVideoDriver *driver, int &slide, int &ti)
{
	slide = 500;

	irr::video::ITexture *tt =
	    driver->getTexture("./assets/menu/My_hunter.png");
	driver->draw2DImage(tt,
	    irr::core::position2d<irr::s32>(220, ti >= 25 ? 25 : ti += 3),
	    irr::core::rect<irr::s32>(0, 0, 656, 253), 0,
	    irr::video::SColor(255, 255, 255, 255), true);

	static int frame = 0;
	static int image_frame = 318;
	irr::video::ITexture *mht =
	    driver->getTexture("./assets/menu/4_eclaire_sprite.png");
	driver->draw2DImage(mht,
	    irr::core::position2d<irr::s32>(ti >= 25 ? 350 : -500, 225),
	    irr::core::rect<irr::s32>(image_frame - 318, 0, image_frame, 312),
	    0, irr::video::SColor(255, 255, 255, 255), true);

	static int frame_cont = 0;

	if (ti >= 25) {
		if (frame < 5) {
			image_frame = 318;
			frame++;
		} else if (frame < 10) {
			image_frame = 636;
			frame++;
		} else
			frame = 0;
		if (frame_cont > 70)
			frame_cont = 0;
		frame_cont++;
	}

	irr::video::ITexture *strt =
	    driver->getTexture("./assets/menu/Pressstart.png");
	driver->draw2DImage(strt,
	    irr::core::position2d<irr::s32>(
		ti >= 25 && frame_cont < 50 ? 200 : -500,
		ti >= 25 && frame_cont < 50 ? 500 : -500),
	    irr::core::rect<irr::s32>(0, 0, 670, 144), 0,
	    irr::video::SColor(255, 255, 255, 255), true);
}

static void drawMenu1(
    irr::video::IVideoDriver *driver, int &slide, int &ti, int &base)
{
	// size button 500, 200
	ti = -350;
	if (slide > 0)
		slide -= 7;
	irr::video::ITexture *but1 =
	    driver->getTexture("./assets/menu/button.png"); // new game
	driver->draw2DImage(but1,
	    irr::core::position2d<irr::s32>(425, slide + 300),
	    irr::core::rect<irr::s32>(
		base == 0 ? 250 : 0, 50, base == 0 ? 500 : 250, 100),
	    0, irr::video::SColor(255, 255, 255, 255), true);

	irr::video::ITexture *but2 =
	    driver->getTexture("./assets/menu/button.png"); // continue
	driver->draw2DImage(but2,
	    irr::core::position2d<irr::s32>(425, slide + 375),
	    irr::core::rect<irr::s32>(
		base == 1 ? 250 : 0, 0, base == 1 ? 500 : 250, 50),
	    0, irr::video::SColor(255, 255, 255, 255), true);

	irr::video::ITexture *but3 =
	    driver->getTexture("./assets/menu/button.png"); // option
	driver->draw2DImage(but3,
	    irr::core::position2d<irr::s32>(425, slide + 450),
	    irr::core::rect<irr::s32>(
		base == 2 ? 250 : 0, 100, base == 2 ? 500 : 250, 150),
	    0, irr::video::SColor(255, 255, 255, 255), true);

	irr::video::ITexture *but4 =
	    driver->getTexture("./assets/menu/button.png"); // exit
	driver->draw2DImage(but4,
	    irr::core::position2d<irr::s32>(425, slide + 525),
	    irr::core::rect<irr::s32>(
		base == 3 ? 250 : 0, 150, base == 3 ? 500 : 250, 200),
	    0, irr::video::SColor(255, 255, 255, 255), true);
}

static void drawMenu3(irr::video::IVideoDriver *driver, int &base)
{
	irr::video::ITexture *bg =
	    driver->getTexture("./assets/menu/menu_bg.jpg");
	driver->draw2DImage(bg, irr::core::position2d<irr::s32>(170, 80),
	    irr::core::rect<irr::s32>(5, 5, 740, 560), 0,
	    irr::video::SColor(255, 255, 255, 255), true);

	irr::video::ITexture *but1 =
	    driver->getTexture("./assets/menu/pause.png"); // pause
	driver->draw2DImage(but1, irr::core::position2d<irr::s32>(425, 90),
	    irr::core::rect<irr::s32>(0, 0, 200, 60), 0,
	    irr::video::SColor(255, 255, 255, 255), true);

	irr::video::ITexture *but2 =
	    driver->getTexture("./assets/menu/pause.png"); // resume
	driver->draw2DImage(but2,
	    irr::core::position2d<irr::s32>(base == 0 ? 425 : 400, 250),
	    irr::core::rect<irr::s32>(
		base == 0 ? 200 : 0, 70, base == 0 ? 400 : 200, 140),
	    0, irr::video::SColor(255, 255, 255, 255), true);

	irr::video::ITexture *but3 =
	    driver->getTexture("./assets/menu/pause.png"); // save
	driver->draw2DImage(but3,
	    irr::core::position2d<irr::s32>(base == 1 ? 425 : 400, 370),
	    irr::core::rect<irr::s32>(
		base == 1 ? 200 : 0, 240, base == 1 ? 400 : 200, 310),
	    0, irr::video::SColor(255, 255, 255, 255), true);

	irr::video::ITexture *but4 =
	    driver->getTexture("./assets/menu/pause.png"); // exit
	driver->draw2DImage(but4,
	    irr::core::position2d<irr::s32>(base == 2 ? 425 : 400, 490),
	    irr::core::rect<irr::s32>(
		base == 2 ? 200 : 0, 320, base == 2 ? 400 : 200, 390),
	    0, irr::video::SColor(255, 255, 255, 255), true);
}

void Menu::drawMain(
    irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver)
{
	static int slide = 500;
	static int ti = -350;
	if (menu == 2) {

		slide = 500;
		clear();
		Game *game = Game::getInstance();
		game->getPlayers()->clear();
		game->getItems()->clear();
		game->loadMap();
		this->_game = true;
		this->setBase(0);
		this->setMenu(3);

	} else if (menu == 3) {
		drawMenu3(driver, base);
	} else {
		irr::video::ITexture *bg =
		    driver->getTexture("./assets/menu/BlueSky.png");
		driver->draw2DImage(bg, irr::core::position2d<irr::s32>(0, 0),
		    irr::core::rect<irr::s32>(0, 0, 1080, 720), 0,
		    irr::video::SColor(255, 255, 255, 255), true);

		irr::video::ITexture *rn =
		    driver->getTexture("./assets/menu/rainbow.png");
		static int i = 0;
		irr::core::recti rt(0, 0, i += 8, 720);
		driver->draw2DImage(rn, irr::core::position2d<irr::s32>(0, 35),
		    irr::core::rect<irr::s32>(0, 0, 1080, 720), &rt,
		    irr::video::SColor(255, 255, 255, 255), true);

		irr::video::ITexture *bd =
		    driver->getTexture("./assets/menu/Mountains.png");
		driver->draw2DImage(bd, irr::core::position2d<irr::s32>(0, 35),
		    irr::core::rect<irr::s32>(0, 0, 1080, 720), 0,
		    irr::video::SColor(255, 255, 255, 255), true);

		if (menu == 0) {
			drawMenu0(driver, slide, ti);
		}
		if (menu == 1) {
			drawMenu1(driver, slide, ti, base);
		}
		if (menu == 5) {
			irr::video::ITexture *bd =
			    driver->getTexture("./assets/menu/how_to_bg.jpg");
			driver->draw2DImage(bd,
			    irr::core::position2d<irr::s32>(35, 35),
			    irr::core::rect<irr::s32>(0, 0, 1000, 600), 0,
			    irr::video::SColor(255, 255, 255, 255), true);
		}
	}
}