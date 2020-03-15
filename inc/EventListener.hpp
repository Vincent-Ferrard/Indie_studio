/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** EventListener
*/

#ifndef EVENTLISTENER_HPP_
#define EVENTLISTENER_HPP_

#include "Utils.hpp"
#include "irrlicht.h"

class EventListener : public irr::IEventReceiver {
      private:
	AppContext Context;
	bool (*_f)(const irr::SEvent &e);

      public:
	EventListener();
	EventListener(AppContext &context);
	virtual bool OnEvent(const irr::SEvent &event);
	void setFunction(bool (*f)(const irr::SEvent &e));
	void setContext(AppContext &context);
};

#endif /* !EVENTLISTENER_HPP_ */