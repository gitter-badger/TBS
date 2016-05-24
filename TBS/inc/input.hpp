#pragma once

#include <functional>
#include <list>
#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>

/**
 * This class allows for binding functions to input events
 */
class InputListener
{
public:
	InputListener() = default;

private:
	typedef std::list<std::function<bool()>> ActionFuncList;
	typedef std::unordered_map<sf::Keyboard::Key, ActionFuncList> ActionMap;

public:
	void BindAction(sf::Keyboard::Key _key, std::function<bool()> _function);
	void ActionPress(sf::Keyboard::Key _key);

private:
	ActionMap m_actionMap;
};
