/*
** EPITECH PROJECT, 2019
** indie (workspace)
** File description:
** Player.cpp
*/

#include "Player.hpp"

#include "Game.hpp"

Player::Player(
    const char *pathTexture, const char *pathMesh, irr::core::vector3df pos)
{
	LibManager *irr = LibManager::getInstance();
	irr::scene::ISceneManager *smgr = irr->getSmgr();

	irr::scene::IAnimatedMesh *mesh = smgr->getMesh(pathMesh);
	if (!mesh)
		exit(84);

	_node = smgr->addAnimatedMeshSceneNode(mesh);
	_node->setPosition(pos);
	if (_node) {
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_node->setScale(irr::core::vector3df(1.6f));
		_node->setMD2Animation(irr::scene::EMAT_POINT);
		_node->setAnimationSpeed(20.f);
		_node->setMaterialTexture(
		    0, irr->getDriver()->getTexture(pathTexture));
	}
	_move = _node->getPosition();
}

std::vector<Bomb *> *Player::getBombs() { return (&_bombs); }

bool Player::isDead() const { return (_dead); }

void Player::dead(bool dead) { _dead = dead; }

void Player::move()
{
	switch (_dir) {
		case 0:
			if (_move.X + 30 > _node->getPosition().X)
				_node->setPosition(irr::core::vector3df(
				    _node->getPosition().X + (5 + 1 * _speed),
				    _node->getPosition().Y, _move.Z));
			else {
				if (!_keyPress)
					_dir = -1;
				_move = _node->getPosition();
			}
			break;
		case 1:
			if (_move.X - 30 < _node->getPosition().X)
				_node->setPosition(irr::core::vector3df(
				    _node->getPosition().X - (5 + 1 * _speed),
				    _node->getPosition().Y, _move.Z));
			else {
				if (!_keyPress)
					_dir = -1;
				_move = _node->getPosition();
			}
			break;
		case 2:
			if (_move.Z + 30 > _node->getPosition().Z)
				_node->setPosition(irr::core::vector3df(_move.X,
				    _node->getPosition().Y,
				    _node->getPosition().Z + (5 + 1 * _speed)));
			else {
				if (!_keyPress)
					_dir = -1;
				_move = _node->getPosition();
			}
			break;
		case 3:
			if (_move.Z - 30 < _node->getPosition().Z)
				_node->setPosition(irr::core::vector3df(_move.X,
				    _node->getPosition().Y,
				    _node->getPosition().Z - (5 + 1 * _speed)));
			else {
				if (!_keyPress)
					_dir = -1;
				_move = _node->getPosition();
			}
			break;
	}
}

void Player::setControllers(int up, int down, int left, int right, int drop)
{
	_controls._up = up;
	_controls._down = down;
	_controls._left = left;
	_controls._right = right;
	_controls._drop = drop;
}

void Player::handleInputEvents(irr::SEvent e)
{
	int key = e.KeyInput.Key;
	irr::core::vector3df vec = getNode()->getPosition();

	if (e.KeyInput.PressedDown)
		_keyPress = true;
	else
		_keyPress = false;

	if (key == _controls._up) {
		_dir = 0;
		getNode()->setRotation(irr::core::vector3df(0, -90, 0));
	} else if (key == _controls._down) {
		_dir = 1;
		getNode()->setRotation(irr::core::vector3df(0, 90, 0));
	} else if (key == _controls._left) {
		_dir = 2;
		getNode()->setRotation(irr::core::vector3df(0, 180, 0));
	} else if (key == _controls._right) {
		_dir = 3;
		getNode()->setRotation(irr::core::vector3df(0, 0, 0));
	} else if (key == _controls._drop) {
		if ((getBombs()->size() < (getNbMaxBomb())) &&
		    e.KeyInput.PressedDown)
			setBomb(new Bomb(
			    getNode()->getPosition(), getPower(), _penetrator));
	}
}