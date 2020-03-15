/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Player_get
*/

#include "Player.hpp"

int Player::getPower() const { return (_power); }

int Player::getSpeed() const { return (_speed); }

std::vector<irr::scene::ISceneNodeAnimator *> *Player::getAnims()
{
	return (&_anims);
};

bool Player::getPenetrator() const { return (_penetrator); }

int Player::getNbMaxBomb() const { return (_nbMaxBomb); }