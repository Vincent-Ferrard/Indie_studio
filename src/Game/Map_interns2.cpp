/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Map_interns2
*/

#include "Game.hpp"
#include "Map.hpp"

std::vector<int> Map::nbrvoidColumn(int x)
{
	std::vector<int> n;

	n.push_back(0);
	n.push_back(0);
	n.push_back(0);
	for (unsigned int y = 0; y < _map.size(); y++) {
		if (_map[y][x] == ' ')
			n[0] = n[0] + 1;
		else if (_map[y][x] == 'B')
			n[1] = n[1] + 1;
	}
	n[2] = n[0] + n[1];
	return n;
}

void Map::thereIsBox(int ix, int iy)
{
	std::vector<int> nbrL;
	std::vector<int> nbrC;

	if (_map[iy][ix] == ' ') {
		nbrL = nbrvoidLine(iy);
		nbrC = nbrvoidColumn(ix);

		float resultL = (float)nbrL[1] / (float)nbrL[2];
		float resultC = (float)nbrC[1] / (float)nbrC[2];
		int r = rand() % 100;

		if (resultC < 0.29 || resultL < 0.29) {
			if ((resultC > 0.71 || resultL > 0.71))
				;
			else if (r <= 75)
				_map[iy][ix] = 'B';
		} else if ((resultL <= 0.71 && resultL >= 0.29) &&
			   (resultC <= 0.71 && resultC >= 0.29)) {
			if (r >= 75)
				;
			else if (resultL <= 0.5 && resultC <= 0.5)
				_map[iy][ix] = 'B';
			else if ((resultL >= 0.5 && resultC <= 0.5) && r <= 40)
				_map[iy][ix] = 'B';
			else if ((resultL <= 0.5 && resultC >= 0.5) && r <= 40)
				_map[iy][ix] = 'B';
			else if ((resultL >= 0.5 && resultC >= 0.5) && r <= 30)
				_map[iy][ix] = 'B';
		}
	}
}

void Map::dispMap()
{
	int i = 0;

	while (_map[i].c_str()) {
		std::cout << _map[i] << std::endl;
		i++;
	}
}

void Map::addPhysicalBox(int ix, int iy, int iz)
{
	irr::scene::ISceneManager *t = LibManager::getInstance()->getSmgr();
	irr::video::IVideoDriver *d = LibManager::getInstance()->getDriver();

	this->_n.push_back(t->addCubeSceneNode());

	if (_n.back()) {
		_n.back()->setMaterialTexture(
		    0, d->getTexture("./assets/box.png"));
		_n.back()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_n.back()->setPosition(irr::core::vector3df(ix, iy, iz));
		_n.back()->setScale(irr::core::vector3df(10, 10, 10));
	}
	irr::scene::ITriangleSelector *selector = 0;

	if (_n.back()) {
		selector = t->createOctreeTriangleSelector(
		    _n.back()->getMesh(), _n.back(), 128);
		_n.back()->setTriangleSelector(selector);
	}
	std::vector<Player *> *players = Game::getInstance()->getPlayers();
	for (unsigned int i = 0; i < players->size(); i++) {
		if (selector) {
			irr::scene::ISceneNodeAnimator *anim =
			    t->createCollisionResponseAnimator(selector,
				(*players)[i]->getNode(),
				irr::core::vector3df(30, 30, 30),
				irr::core::vector3df(0, 0, 0),
				irr::core::vector3df(10, -30, 10));
			(*players)[i]->getNode()->addAnimator(anim);
			(*players)[i]->getAnims()->push_back(anim);
			// anim->drop();
		}
	}
	selector->drop();
}

void Map::addPhysicalWall(int ix, int iy, int iz)
{
	irr::scene::ISceneManager *t = LibManager::getInstance()->getSmgr();
	irr::video::IVideoDriver *d = LibManager::getInstance()->getDriver();

	this->_n.push_back(t->addCubeSceneNode());

	if (_n.back()) {
		_n.back()->setMaterialTexture(
		    0, d->getTexture("./assets/rockwall.jpg"));
		_n.back()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_n.back()->setPosition(irr::core::vector3df(ix, iy, iz));
		_n.back()->setScale(irr::core::vector3df(10, 10, 10));
	}
	irr::scene::ITriangleSelector *selector = 0;

	if (_n.back()) {
		selector = t->createOctreeTriangleSelector(
		    _n.back()->getMesh(), _n.back(), 128);
		_n.back()->setTriangleSelector(selector);
	}
	std::vector<Player *> *players = Game::getInstance()->getPlayers();
	for (unsigned int i = 0; i < players->size(); i++) {
		if (selector) {
			irr::scene::ISceneNodeAnimator *anim =
			    t->createCollisionResponseAnimator(selector,
				(*players)[i]->getNode(),
				irr::core::vector3df(30, 30, 30),
				irr::core::vector3df(0, 0, 0),
				irr::core::vector3df(10, -30, 10));
			(*players)[i]->getNode()->addAnimator(anim);
			(*players)[i]->getAnims()->push_back(anim);
			// anim->drop();
		}
	}
	selector->drop();
}