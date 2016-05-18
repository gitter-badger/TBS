#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

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
	float FPS;                                 // Frames per second
	sf::RenderWindow &m_renderWindow;          // The window
	std::vector<sf::ConvexShape> m_hexagons;   // A simple hexagon shape
	sf::Font m_fntArial;                       // Font
	sf::Text m_txtFPS;						   // Text
	float m_lastFPSUpdate;                     // The time of when the fps was updated last
};
