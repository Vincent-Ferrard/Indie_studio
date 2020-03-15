/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Player_set
*/

#include "Bomb.hpp"
#include "Player.hpp"

void Player::setBomb(Bomb *bomb) { _bombs.push_back(bomb); }

void Player::incPower() { _power++; }

void Player::incSpeed()
{
	if (_speed < 10)
		_speed++;
}

void Player::incNbMaxBomb() { _nbMaxBomb++; }

void Player::penetrator()
{
	if (!_penetrator)
		_penetrator = true;
}