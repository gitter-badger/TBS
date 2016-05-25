#pragma once

#include <functional>
#include <list>
#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>

// Input events
enum InputTriggers : std::uint8_t
{
	Press = 1 << 0,
	Release = 1 << 1,
};

/**
 * This class allows for binding functions to input events
 */
class InputListener
{
public:
	InputListener() = default;

private:
	struct Event {
		std::uint8_t triggers;
		std::function<bool()> function;
	};
	typedef std::list<Event> ActionFuncList;
	typedef std::unordered_map<sf::Keyboard::Key, ActionFuncList> ActionMap;

public:
	void Bind(sf::Keyboard::Key _key, std::uint8_t _triggers, std::function<bool()> _function);
	void ActionPress(sf::Keyboard::Key _key);
	void ActionRelease(sf::Keyboard::Key _key);

private:
	void TriggerEvents(sf::Keyboard::Key _key, std::uint8_t _trigger);

private:
	ActionMap m_actionMap;
};

// Global input listener object, definition in input.cpp
extern InputListener g_inputListener;
