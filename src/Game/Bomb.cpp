/*
** EPITECH PROJECT, 2019
** indie (workspace)
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"

#include "Game.hpp"

Bomb::Bomb(irr::core::vector3df pos, int power, bool penetrator)
	: _power(power), _penetrator(penetrator)
{
	LibManager *irr = LibManager::getInstance();

	irr::scene::IAnimatedMesh *mesh =
	    irr->getSmgr()->getMesh("./assets/earth.x");
	if (!mesh)
		exit(84);

	_node = irr->getSmgr()->addAnimatedMeshSceneNode(mesh);
	_node->setPosition(irr::core::vector3df(((int)pos.X + 50) / 100 * 100,
	    pos.Y + 15, ((int)pos.Z + 50) / 100 * 100));
	if (_node) {
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_node->setScale(irr::core::vector3df(1.6f));
		_node->setMD2Animation(irr::scene::EMAT_POINT);
		_node->setAnimationSpeed(18.f);
		_node->setMaterialTexture(
		    0, irr->getDriver()->getTexture("./assets/earth.jpg"));
		_node->setScale(irr::core::vector3df(15, 15, 15));
	}
	_node->setLoopMode(false);
	_animation = new EndAnimationBomb();
	_node->setAnimationEndCallback(_animation);
}

Bomb::~Bomb()
{
	LibManager::getInstance()->getSmgr()->addToDeletionQueue(_node);
}

int Bomb::getPower() const { return (_power); }

bool Bomb::getPenetrator() const { return (_penetrator); }

void checkBoxExplosion(
    irr::scene::IAnimatedMeshSceneNode *node, std::vector<Player *> *players)
{
	std::vector<irr::scene::IMeshSceneNode *> *nodeMap =
	    Game::getInstance()->getMap()->getNodesMap();
	std::vector<std::string> *stringMap =
	    Game::getInstance()->getMap()->getStringMap();
	int j = 0;

	for (auto i = nodeMap->begin(); i < nodeMap->end(); i++, j++) {
		if ((*nodeMap)[j]->getPosition().X + 100 >
			node->getPosition().X + 50 &&
		    (*nodeMap)[j]->getPosition().X <
			node->getPosition().X + 50 &&
		    (*nodeMap)[j]->getPosition().Z + 100 >
			node->getPosition().Z + 50 &&
		    (*nodeMap)[j]->getPosition().Z <
			node->getPosition().Z + 50 &&
		    (*stringMap)[node->getPosition().Z / 100]
				[node->getPosition().X / 100] == 'B') {
			for (unsigned int k = 0; k < players->size(); k++) {
				std::vector<irr::scene::ISceneNodeAnimator *>
				    *anims = (*players)[k]->getAnims();
				auto a = anims->begin();
				for (int b = 0; a < anims->end(); a++, b++)
					if (b == j)
						break;
				irr::scene::ISceneNodeAnimator *anim =
				    (*(*players)[k]->getAnims())[j];
				(*players)[k]->getNode()->removeAnimator(anim);
				anim->drop();
				(*players)[k]->getAnims()->erase(a);
			}
			(*stringMap)[node->getPosition().Z / 100]
				    [node->getPosition().X / 100] = ' ';
			LibManager::getInstance()
			    ->getSmgr()
			    ->addToDeletionQueue((*nodeMap)[j]);
			dropItem(node->getPosition());
			nodeMap->erase(i);
		}
	}
}