/*
** EPITECH PROJECT, 2019
** indie (workspace)
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "irrlicht.h"

class Entity {
      public:
	irr::scene::IAnimatedMeshSceneNode *getNode() const { return (_node); };

      protected:
	irr::scene::IAnimatedMeshSceneNode *_node;
};

#endif /* !ENTITY_HPP_ */
