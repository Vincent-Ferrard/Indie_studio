/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** LibManager_getset
*/

#include "Exception.hpp"
#include "LibManager.hpp"

LibManager *LibManager::getInstance()
{
	if (_instance == nullptr)
		_instance = new LibManager();
	return (_instance);
}

irr::IrrlichtDevice *LibManager::getDevice() const
{
	if (this == nullptr || _device == nullptr)
		throw Exception("LibManager: no instance or device existing");
	return (_device);
}

irr::video::IVideoDriver *LibManager::getDriver() const
{
	if (this == nullptr || _driver == nullptr)
		throw Exception("LibManager: no instance or driver existing");
	return (_driver);
}

irr::scene::ISceneManager *LibManager::getSmgr() const
{
	if (this == nullptr || _smgr == nullptr)
		throw Exception("LibManager: no instance or smgr existing");
	return (_smgr);
}

irr::gui::IGUIEnvironment *LibManager::getGui() const
{
	if (this == nullptr || _gui == nullptr)
		throw Exception("LibManager: no instance or gui existing");
	return (_gui);
}