/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** LibManager
*/

#include "LibManager.hpp"

#include "Exception.hpp"

LibManager::LibManager()
	: _device(nullptr), _driver(nullptr), _gui(nullptr), _smgr(nullptr)
{}

LibManager::~LibManager()
{
	if (_device)
		delete _device;
	if (_driver)
		delete _driver;
	if (_gui)
		delete _gui;
	if (_smgr)
		delete _smgr;
}

void LibManager::init()
{
	_device = irr::createDevice(irr::video::EDT_OPENGL,
	    irr::core::dimension2d<irr::u32>(1080, 720));
	if (_device == nullptr)
		throw Exception("Failed to create device");
	_device->setWindowCaption(L"Bomberman");
	_device->setResizable(false);
	_driver = _device->getVideoDriver();
	_smgr = _device->getSceneManager();
	_gui = _device->getGUIEnvironment();
	irr::gui::IGUISkin *skin = _gui->getSkin();
	irr::gui::IGUIFont *font = _gui->getFont("./assets/font/Bombeman.xml");
	if (font)
		skin->setFont(font);
	skin->setFont(_gui->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
	_device->getCursorControl()->setVisible(false);
}

LibManager *LibManager::_instance = nullptr;

void LibManager::setEventListener(EventListener *ev)
{
	_device->setEventReceiver(ev);
}