#include <algorithm>
#include "input.hpp"

void InputListener::BindAction(sf::Keyboard::Key _key, std::function<bool()> _function)
{
	// Make a list if there is none
	if (m_actionMap.find(_key) == m_actionMap.end())
	{
		m_actionMap.insert(std::make_pair(_key, ActionFuncList()));
	}

	// Push instance and action function to the list
	m_actionMap[_key].push_front(_function);
}

void InputListener::ActionPress(sf::Keyboard::Key _key)
{
	// Check if a list exist for this key
	if (m_actionMap.find(_key) == m_actionMap.end())
	{
		return;
	}

	// Trigger all bound functions in order until one catches it
	auto &list = m_actionMap[_key];
	std::all_of(list.begin(), list.end(), [](auto function) -> bool {
		return function();
	});
}
