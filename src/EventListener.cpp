/*
** EPITECH PROJECT, 2019
** indie (Workspace)
** File description:
** EventListener
*/

#include "EventListener.hpp"

#include <iostream>

EventListener::EventListener() : Context(), _f(nullptr) {}

EventListener::EventListener(AppContext &context)
	: Context(context), _f(nullptr)
{}

bool EventListener::OnEvent(const irr::SEvent &event)
{
	if (_f == nullptr)
		return (false);
	return (_f)(event);
}

void EventListener::setFunction(bool (*f)(const irr::SEvent &e)) { _f = f; }

void EventListener::setContext(AppContext &context) { Context = context; }