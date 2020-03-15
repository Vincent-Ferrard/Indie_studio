/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <irrlicht.h>
#include <vector>

class Map {
      private:
	std::vector<std::string> _map;
	std::vector<irr::scene::IMeshSceneNode *> _n;
	int _x;
	int _y;

      public:
	Map(int x, int y);
	~Map();
	void setBox();
	void thereIsBox(int ix, int iy);
	std::vector<int> nbrvoidColumn(int x);
	std::vector<int> nbrvoidLine(int y);
	void setPlayer();
	void dispMap();
	void creatMap();
	std::string voidLine(int x);
	std::string caseLine(int x);
	std::string fullLine(int x);
	void setPhysicalMap();
	void addPhysicalBox(int ix, int iy, int iz);
	void addPhysicalWall(int ix, int iy, int iz);
	irr::scene::ISceneNode *createPlane(irr::core::vector2d<irr::f32>);
	std::vector<irr::scene::IMeshSceneNode *> *getNodesMap();
	std::vector<std::string> *getStringMap();
	int getX() const;
	int getY() const;
	void importMap(std::vector<std::string> *map);
};

#endif /* !MAP_HPP_ */