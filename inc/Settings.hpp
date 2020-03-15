/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

class Settings {
      private:
	Settings();
	static Settings *_instance;

      private:
	char _volume;

      public:
	static Settings *getInstance();
	void setVolume(char vol);
	char getVolume() const;
};

#endif /* !SETTINGS_HPP_ */
