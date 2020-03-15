/*
** EPITECH PROJECT, 2019
** indie (workspace)
** File description:
** Item.hpp
*/

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include "Game.hpp"
#include "Player.hpp"
#include "LibManager.hpp"

#include <iostream>

class IItem : public Entity {
      public:
	IItem(const char *pathTexture, const char *pathMesh,
	    irr::core::vector3df pos)
	{
		LibManager *irr = LibManager::getInstance();

		irr::scene::IAnimatedMesh *mesh =
		    irr->getSmgr()->getMesh(pathMesh);
		if (!mesh)
			exit(84);

		_node = irr->getSmgr()->addAnimatedMeshSceneNode(mesh);
		_node->setPosition(pos);
		if (_node) {
			_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_node->setScale(irr::core::vector3df(1.6f));
			_node->setMD2Animation(irr::scene::EMAT_POINT);
			_node->setAnimationSpeed(18.f);
			_node->setMaterialTexture(
			    0, irr->getDriver()->getTexture(pathTexture));
		}
	}
	virtual ~IItem()
	{
		LibManager::getInstance()->getSmgr()->addToDeletionQueue(_node);
	};
	virtual void action(Player *) = 0;
	virtual std::string getType() const = 0;
};

class PowerUp : public IItem {
      public:
	PowerUp(const char *pathTexture, const char *pathMesh,
	    irr::core::vector3df pos)
		: IItem(pathTexture, pathMesh, pos)
	{}
	void action(Player *player) { player->incPower(); }
	std::string getType() const { return ("PowerUp"); }
};

class BombUp : public IItem {
      public:
	BombUp(const char *pathTexture, const char *pathMesh,
	    irr::core::vector3df pos)
		: IItem(pathTexture, pathMesh, pos)
	{}
	void action(Player *player) { player->incNbMaxBomb(); }
	std::string getType() const { return ("BombUp"); }
};

class SpeedUp : public IItem {
      public:
	SpeedUp(const char *pathTexture, const char *pathMesh,
	    irr::core::vector3df pos)
		: IItem(pathTexture, pathMesh, pos)
	{}
	void action(Player *player) { player->incSpeed(); }
	std::string getType() const { return ("SpeedUp"); }
};

class Penetrator : public IItem {
      public:
	Penetrator(const char *pathTexture, const char *pathMesh,
	    irr::core::vector3df pos)
		: IItem(pathTexture, pathMesh, pos)
	{}
	void action(Player *player) { player->penetrator(); }
	std::string getType() const { return ("Penetrator"); }
};

#endif /* !ITEM_HPP_ */
