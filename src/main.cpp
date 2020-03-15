/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** main
*/

#include "Bomberman.hpp"
#include "Map.hpp"

int main(int ac, char **av)
{
	Bomberman *bomber = Bomberman::getInstance();
	EventListener *e = new EventListener();
	AppContext context;

	context.menu = bomber->getMenu();
	bomber->init(context, e);
	bomber->run(e);
	return (EXIT_SUCCESS);
}