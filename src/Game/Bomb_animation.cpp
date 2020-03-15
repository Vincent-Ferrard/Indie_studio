/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Bomb_animation
*/

#include "Bomb.hpp"
#include "Game.hpp"

int canPutBomb(int actual, int power, bool penetrator,
    std::vector<std::string> stringMap, irr::core::vector3df pos)
{
	if (stringMap[pos.Z / 100][pos.X / 100] == '#')
		actual = power;
	else {
		if (stringMap[pos.Z / 100][pos.X / 100] == 'B' && !penetrator)
			actual = power;
		new Explosion(pos);
	}
	return (actual);
}

void EndAnimationBomb::OnAnimationEnd(irr::scene::IAnimatedMeshSceneNode *node)
{
	std::vector<Player *> *players = Game::getInstance()->getPlayers();
	int j;
	int power = 0;
	bool penetrator = false;

	for (unsigned int i = 0; i < players->size(); i++) {
		std::vector<Bomb *> *bombs = (*players)[i]->getBombs();
		j = 0;
		for (auto i = bombs->begin(); i < bombs->end(); i++, j++)
			if (node == (*bombs)[j]->getNode()) {
				power = (*bombs)[j]->getPower();
				penetrator = (*bombs)[j]->getPenetrator();
				delete (*bombs)[j];
				bombs->erase(i);
			}
	}
	irr::core::vector3df vec = node->getPosition();
	std::vector<std::string> *stringMap =
	    Game::getInstance()->getMap()->getStringMap();

	new Explosion(irr::core::vector3df(vec.X, vec.Y + 25, vec.Z));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < power; j++) switch (i) {
				case 0:
					j = canPutBomb(j, power, penetrator,
					    *stringMap,
					    irr::core::vector3df(
						vec.X + 100 * (j + 1),
						vec.Y + 25, vec.Z));
					break;
				case 1:
					j = canPutBomb(j, power, penetrator,
					    *stringMap,
					    irr::core::vector3df(
						vec.X - 100 * (j + 1),
						vec.Y + 25, vec.Z));
					break;
				case 2:
					j = canPutBomb(j, power, penetrator,
					    *stringMap,
					    irr::core::vector3df(vec.X,
						vec.Y + 25,
						vec.Z + 100 * (j + 1)));
					break;
				case 3:
					j = canPutBomb(j, power, penetrator,
					    *stringMap,
					    irr::core::vector3df(vec.X,
						vec.Y + 25,
						vec.Z - 100 * (j + 1)));
					break;
			}
}

Explosion::Explosion(irr::core::vector3df pos)
{
	LibManager *irr = LibManager::getInstance();

	irr::scene::IAnimatedMesh *mesh =
	    irr->getSmgr()->getMesh("./assets/faerie.md2");
	if (!mesh)
		exit(84);

	_node = irr->getSmgr()->addAnimatedMeshSceneNode(mesh);
	_node->setPosition(pos);
	if (_node) {
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_node->setScale(irr::core::vector3df(1.6f));
		_node->setMD2Animation(irr::scene::EMAT_POINT);
		_node->setAnimationSpeed(80.f);
		_node->setMaterialTexture(
		    0, irr->getDriver()->getTexture("./assets/faerie2.bmp"));
	}

	_node->setLoopMode(false);
	_animation = new EndAnimationExplosion();
	_node->setAnimationEndCallback(_animation);
}

void EndAnimationExplosion::OnAnimationEnd(
    irr::scene::IAnimatedMeshSceneNode *node)
{
	std::vector<Player *> *players = Game::getInstance()->getPlayers();

	for (unsigned int i = 0; i < players->size(); i++) {
		if (!(*players)[i]->isDead() &&
		    (*players)[i]->getNode()->getPosition().X >=
			node->getPosition().X - 50 &&
		    (*players)[i]->getNode()->getPosition().X <=
			node->getPosition().X + 50 &&
		    (*players)[i]->getNode()->getPosition().Z >=
			node->getPosition().Z - 50 &&
		    (*players)[i]->getNode()->getPosition().Z <=
			node->getPosition().Z + 50) {
			(*players)[i]->dead(true);
			LibManager::getInstance()
			    ->getSmgr()
			    ->addToDeletionQueue((*players)[i]->getNode());
		}
	}
	checkBoxExplosion(node, players);
	LibManager::getInstance()->getSmgr()->addToDeletionQueue(node);
}

void dropItem(irr::core::vector3df pos)
{
	int value = rand() % 100;

	if (value >= 25 && value <= 99)
		return;
	else if (value >= 0 && value < 7)
		Game::getInstance()->getItems()->push_back(new PowerUp(
		    "./assets/Faerie5.BMP", "./assets/faerie.md2", pos));
	else if (value >= 7 && value < 14)
		Game::getInstance()->getItems()->push_back(
		    new BombUp("./assets/dwarf.jpg", "./assets/dwarf.x", pos));
	else if (value >= 14 && value < 21)
		Game::getInstance()->getItems()->push_back(new SpeedUp(
		    "./assets/faerie2.bmp", "./assets/faerie.md2", pos));
	else
		Game::getInstance()->getItems()->push_back(new Penetrator(
		    "./assets/sydney.bmp", "./assets/sydney.md2", pos));
}