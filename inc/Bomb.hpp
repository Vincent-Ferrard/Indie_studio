/*
** EPITECH PROJECT, 2019
** indie (workspace)
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Entity.hpp"

#include <irrlicht.h>
#include <vector>

class EndAnimationBomb : public irr::scene::IAnimationEndCallBack {
      public:
	void OnAnimationEnd(irr::scene::IAnimatedMeshSceneNode *);
};

class Bomb : public Entity {
      public:
	Bomb(irr::core::vector3df, int, bool);
	~Bomb();
	int getPower() const;
	bool getPenetrator() const;

      private:
	EndAnimationBomb *_animation;
	int _power;
	bool _penetrator;
};

class EndAnimationExplosion : public irr::scene::IAnimationEndCallBack {
      public:
	void OnAnimationEnd(irr::scene::IAnimatedMeshSceneNode *);
};

class Explosion : public Entity {
      public:
	Explosion(irr::core::vector3df);

      private:
	EndAnimationExplosion *_animation;
};

void dropItem(irr::core::vector3df);

#endif /* !BOMB_HPP_ */
