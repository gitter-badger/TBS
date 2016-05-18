#pragma once

#include <SFML/Graphics.hpp>

class RTSGame
{
public:
	RTSGame(sf::RenderWindow &_renderWindow);

public: //Input events
	void KeyPressed(sf::Keyboard::Key);
	void KeyReleased(sf::Keyboard::Key);
	void MouseMove(int _x, int _y);
	void MouseDown(sf::Mouse::Button _button, int _x, int _y);
	void MouseUp(sf::Mouse::Button _button, int x, int y);
	void MouseWheelScrolled(int _delta);

public: // Methods
	void Initialize();
	void Tick(float _deltaSeconds);
	void Render();

private: // Data members
	float m_totalSeconds;                      // Seconds passed since startup
	sf::RenderWindow &m_renderWindow;          // The window
	sf::ConvexShape m_hexagon;                 // A simple hexagon shape
};