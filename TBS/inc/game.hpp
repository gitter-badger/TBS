#pragma once

#include <SFML/Graphics.hpp>

// Pimpl
class TBSGame;

/**
 * Game Interface
 */
class IGame
{
public: // Constructors and destructor
	IGame(sf::RenderWindow &_renderWindow);
	IGame(IGame&) = default;
	IGame& operator=(IGame&) = default;
	virtual ~IGame() = default;

public: //Input events
	void MouseMove(int _x, int _y);
	void MouseDown(sf::Mouse::Button _button, int _x, int _y);
	void MouseUp(sf::Mouse::Button _button, int x, int y);
	void MouseWheelScrolled(int _delta);

public: // Methods
	void Initialize();
	void Tick(float _deltaSeconds);
	void Render();

private:
	TBSGame *m_TBSGame;                        // The game class handling the logic
};
