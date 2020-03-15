/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Bomberman
*/

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include <ctime>
#include "EventListener.hpp"
#include "Game.hpp"
#include "LibManager.hpp"
#include "Settings.hpp"

class Bomberman {
      private:
	Bomberman();
	~Bomberman();
	static Bomberman *_instance;
	LibManager *_irr;
	EventListener *_ev;
	Menu *_menu;
	Settings *_settings;
	Game *_game;

      public:
	static Bomberman *getInstance();
	void init(AppContext &context, EventListener *listener);
	void setEventListener(EventListener *ev);
	void run(EventListener *listener);

      public:
	Menu *getMenu() const;
	Game *getGame() const;
	int getVolume() const;
	void setVolume(int vol);
};

#endif /* !BOMBERMAN_HPP_ */