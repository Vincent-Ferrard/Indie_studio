/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Map
*/

#include "Map.hpp"

#include "Game.hpp"

Map::Map(int x, int y)
{
	if (x < 5 && y < 5) {
		std::cerr << "Error: map's size" << std::endl;
		return;
	}
	this->_x = x;
	this->_y = y;

	creatMap();
	setPlayer();
	setBox();
	setPhysicalMap();
	createPlane(irr::core::vector2d<irr::f32>(100 * 21, 100 * 13));
	return;
}

Map::~Map() {}

irr::scene::ISceneNode *Map::createPlane(
    irr::core::vector2d<irr::f32> dimensions)
{
	const irr::scene::IGeometryCreator *gcreator =
	    LibManager::getInstance()->getSmgr()->getGeometryCreator();
	irr::scene::IMesh *plane = gcreator->createPlaneMesh(
	    dimensions, irr::core::dimension2du(1, 1));
	irr::scene::ISceneNode *ground =
	    LibManager::getInstance()->getSmgr()->addMeshSceneNode(plane);
	irr::scene::ITriangleSelector *selector = 0;

	ground->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ground->setPosition(
	    irr::core::vector3df(20 * 100 / 2, -50, 12 * 100 / 2));
	ground->setMaterialTexture(
	    0, LibManager::getInstance()->getDriver()->getTexture(
		   "assets/grass.png"));
	LibManager::getInstance()
	    ->getSmgr()
	    ->getMeshManipulator()
	    ->makePlanarTextureMapping(plane->getMeshBuffer(0), 0.04f);
	if (ground) {
		selector = LibManager::getInstance()
			       ->getSmgr()
			       ->createTriangleSelector(plane, ground);
		ground->setTriangleSelector(selector);
	}
	for (unsigned int i = 0; i < _n.size(); i++) {
		if (selector) {
			irr::scene::ISceneNodeAnimator *anim =
			    LibManager::getInstance()
				->getSmgr()
				->createCollisionResponseAnimator(selector,
				    _n[i], irr::core::vector3df(30, 30, 30),
				    irr::core::vector3df(0, -10, 0),
				    irr::core::vector3df(0, 30, 0));
			_n[i]->addAnimator(anim);
			anim->drop();
		}
	}
	std::vector<Player *> *players = Game::getInstance()->getPlayers();
	for (unsigned int i = 0; i < players->size(); i++) {
		if (selector) {
			irr::scene::ISceneNodeAnimator *anim =
			    LibManager::getInstance()
				->getSmgr()
				->createCollisionResponseAnimator(selector,
				    (*players)[i]->getNode(),
				    irr::core::vector3df(30, 30, 30),
				    irr::core::vector3df(0, -10, 0),
				    irr::core::vector3df(0, -30, 0));
			(*players)[i]->getNode()->addAnimator(anim);
			anim->drop();
		}
	}
	selector->drop();
	return ground;
}