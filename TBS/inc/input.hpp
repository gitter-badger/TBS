#pragma once

#include <functional>
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
	static void Bind(sf::Keyboard::Key _key, std::uint8_t _triggers, std::function<bool()> _function);
	static void ActionPress(sf::Keyboard::Key _key);
	static void ActionRelease(sf::Keyboard::Key _key);
};
