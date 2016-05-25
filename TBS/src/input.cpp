#include <algorithm>
#include "input.hpp"

InputListener g_inputListener;

void InputListener::Bind(sf::Keyboard::Key _key, std::uint8_t _triggers, std::function<bool()> _function)
{
	// Make a list if there is none
	if (m_actionMap.find(_key) == m_actionMap.end())
	{
		m_actionMap.insert(std::make_pair(_key, ActionFuncList()));
	}

	// Push instance and action function to the list
	m_actionMap[_key].push_front(Event({ _triggers, _function }));
}

void InputListener::ActionPress(sf::Keyboard::Key _key)
{
	TriggerEvents(_key, InputTriggers::Press);
}

void InputListener::ActionRelease(sf::Keyboard::Key _key)
{
	TriggerEvents(_key, InputTriggers::Release);
}

void InputListener::TriggerEvents(sf::Keyboard::Key _key, std::uint8_t _trigger)
{
	// Check if a list exist for this key
	if (m_actionMap.find(_key) == m_actionMap.end())
	{
		return;
	}

	// Trigger all bound functions in order until one catches it
	auto &list = m_actionMap[_key];
	std::all_of(list.begin(), list.end(), [=](Event _event) -> bool {
		if (_event.triggers & _trigger)
			return _event.function();
		return true;
	});
}
