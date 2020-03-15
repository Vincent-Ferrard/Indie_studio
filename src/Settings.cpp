/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Settings
*/

#include "Settings.hpp"

Settings::Settings() : _volume(50) {}

Settings *Settings::_instance = nullptr;

Settings *Settings::getInstance()
{
	if (_instance == nullptr)
		_instance = new Settings();
	return (_instance);
}

void Settings::setVolume(char vol)
{
	if (_volume != vol && vol >= 0 && vol <= 100)
		_volume = vol;
}

char Settings::getVolume() const { return (_volume); }