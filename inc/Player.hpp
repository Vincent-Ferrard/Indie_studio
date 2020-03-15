/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Bomb.hpp"

#include <irrlicht.h>
#include <utility>

class Controls {
	public:
		Controls(int up, int down, int left, int right, int drop) : _up(up), _down(down), _left(left), _right(right), _drop(drop){};
		Controls(){};
		~Controls(){};
		int _up;
		int _down;
		int _left;
		int _right;
		int _drop;
};

class Player : public Entity {
      public:
	Player(const char *, const char *, irr::core::vector3df);
	std::vector<Bomb *> *getBombs();
	void setBomb(Bomb *);
	int getPower() const;
	void incPower();
	int getSpeed() const;
	void incSpeed();
	int getNbMaxBomb() const;
	void incNbMaxBomb();
	bool getPenetrator() const;
	void penetrator();
	void dead(bool);
	bool isDead() const;
	std::vector<irr::scene::ISceneNodeAnimator *> *getAnims();
	void move();
	void setControllers(int up, int down, int left, int right, int drop);
	void handleInputEvents(irr::SEvent e);

      private:
	std::pair<int, int> _pos;
	std::vector<Bomb *> _bombs;
	std::vector<irr::scene::ISceneNodeAnimator *> _anims;
	int _power = 1;
	int _speed = 0;
	int _nbMaxBomb = 1;
	bool _penetrator = false;
	bool _dead = false;
	int _dir = -1;
	bool _keyPress = false;
	irr::core::vector3df _move;
	Controls _controls;
};

void checkBoxExplosion(
    irr::scene::IAnimatedMeshSceneNode *, std::vector<Player *> *);

#endif /* !PLAYER_HPP_ */