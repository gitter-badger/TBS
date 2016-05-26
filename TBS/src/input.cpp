#include <algorithm>
#include <list>
#include <unordered_map>
#include "input.hpp"

InputListener g_inputListener;

// Implementation of the input class
class InputListener_imp
{
	friend class InputListener;

private:
	struct Event
	{
		std::uint8_t triggers;
		std::function<bool()> function;
	};
	typedef std::list<Event> ActionFuncList;
	typedef std::unordered_map<sf::Keyboard::Key, ActionFuncList> ActionMap;

private:
	void TriggerEvents(sf::Keyboard::Key _key, std::uint8_t _trigger);

private:
	ActionMap m_actionMap;
};

InputListener_imp st_input;

void InputListener::Bind(sf::Keyboard::Key _key, std::uint8_t _triggers, std::function<bool()> _function)
{
	// Make a list if there is none
	if (st_input.m_actionMap.find(_key) == st_input.m_actionMap.end())
	{
		st_input.m_actionMap.insert(std::make_pair(_key, InputListener_imp::ActionFuncList()));
	}

	// Push instance and action function to the list
	st_input.m_actionMap[_key].push_front(InputListener_imp::Event({ _triggers, _function }));
}

void InputListener::ActionPress(sf::Keyboard::Key _key)
{
	st_input.TriggerEvents(_key, InputTriggers::Press);
}

void InputListener::ActionRelease(sf::Keyboard::Key _key)
{
	st_input.TriggerEvents(_key, InputTriggers::Release);
}

void InputListener_imp::TriggerEvents(sf::Keyboard::Key _key, std::uint8_t _trigger)
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
