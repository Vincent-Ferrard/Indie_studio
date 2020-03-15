/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** LibManager
*/

#ifndef LIBMANAGER_HPP_
#define LIBMANAGER_HPP_

#include "EventListener.hpp"
#include "irrlicht.h"

class LibManager {
      private:
	irr::IrrlichtDevice *_device;
	irr::video::IVideoDriver *_driver;
	irr::gui::IGUIEnvironment *_gui;
	irr::scene::ISceneManager *_smgr;
	static LibManager *_instance;
	LibManager();

      public:
	~LibManager();
	static LibManager *getInstance();
	void updateDisplay();
	void init();
	void setEventListener(EventListener *ev);

      public:
	irr::IrrlichtDevice *getDevice() const;
	irr::video::IVideoDriver *getDriver() const;
	irr::scene::ISceneManager *getSmgr() const;
	irr::gui::IGUIEnvironment *getGui() const;
};

#endif /* !LIBMANAGER_HPP_ */