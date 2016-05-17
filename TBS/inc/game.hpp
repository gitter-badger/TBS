#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
	// Constructor
	Game(sf::RenderWindow &_renderWindow);

public: //Input events
	void KeyPressed(sf::Keyboard::Key);
	void KeyReleased(sf::Keyboard::Key);
	void MouseMove(int _x, int _y);
	void MouseDown(sf::Mouse::Button _button, int _x, int _y);
	void MouseUp(sf::Mouse::Button _button, int x, int y);
	void MouseWheelScrolled(int _delta);

	// Methods
	void Initialize();                // Called to initialize the game
	void Tick(float _deltaSeconds);   // Do the game logic
	void Render();                    // Render method

private:
	// Data members
	float m_totalSeconds;             // Seconds passed since startup
	sf::RenderWindow &m_renderWindow; // The window
	sf::Font m_font;                  // A font
	bool m_mouseDown;                 // flag for the left mouse button
	sf::Vector2i m_mousePosition;     // Screen position of the mouse
};
