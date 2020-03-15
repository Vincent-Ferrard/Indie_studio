/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Saver
*/

#ifndef SAVER_HPP_
#define SAVER_HPP_

#include "Exception.hpp"
#include "Player.hpp"
#include "Map.hpp"

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <set>
#include <string>

namespace pt = boost::property_tree;

class Saver {
      private:
	Saver();
	static Saver *_instance;
	std::string _filename;
	pt::ptree *_tree;

      private:
	void SavePlayers();
	void SaveMap();
	Map *LoadMap();
	std::vector<Player *> *LoadPlayers();

      public:
	static Saver *getInstance();
	pt::ptree *getTree() const;
	void setFilename(const std::string &filename);
	void write();
	void SaveGame();
	void LoadGame();
};

#endif /* !SAVER_HPP_ */