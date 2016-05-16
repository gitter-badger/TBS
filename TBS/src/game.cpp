#include "game.hpp"

Game::Game(sf::RenderWindow &_renderWindow)
	: m_renderWindow(_renderWindow)
	, m_totalSeconds(0.0f)
{
}

static sf::CircleShape gHexagon(50.0f, 6);
void Game::Initialize()
{
	gHexagon.setOrigin(50.0f, 50.0f);
	gHexagon.setPosition(m_renderWindow.getSize().x / 2.0f, m_renderWindow.getSize().y / 2.0f);
}

void Game::KeyPressed(sf::Keyboard::Key _keyCode)
{
	switch (_keyCode)
	{
	case sf::Keyboard::Unknown: // Caps Lock, Scroll Lock, Num Lock
		std::puts("An unknown key has been pressed!");
		break;

	default:
		std::printf("Code of key being pressed: %d.\n", _keyCode);
		break;
	} // switch _keyCode
}

void Game::KeyReleased(sf::Keyboard::Key _keyCode)
{
	switch (_keyCode)
	{
	case sf::Keyboard::Unknown:
		// Unknown key has been released
		break;
	default:
		break;
	} // switch _keyCode
}

void Game::MouseMove(int _x, int _y)
{
	// Update the stored mouse position
	m_mousePosition.x = _x;
	m_mousePosition.y = _y;
}

void Game::MouseDown(sf::Mouse::Button _button, int _x, int _y)
{
	// Switch on the pressed button
	switch (_button)
	{
	case sf::Mouse::Left:
		m_mouseDown = true;
		break;
	case sf::Mouse::Right:
		break;
	case sf::Mouse::Middle:
		break;
	}
}

void Game::MouseUp
(sf::Mouse::Button _button, int _x, int _y)
{
	// Switch on the released button
	switch (_button)
	{
	case sf::Mouse::Left:
		m_mouseDown = false;
		break;
	case sf::Mouse::Right:
		break;
	case sf::Mouse::Middle:
		break;
	}
}

void Game::MouseWheelScrolled(int _delta)
{

}

void Game::Tick(float _deltaSeconds)
{
	// Increase the game time
	m_totalSeconds += _deltaSeconds;

	// Game logic here
	gHexagon.rotate(_deltaSeconds * 180.0f / 3.14159265f);
}

void Game::Render()
{
	// Render logic
	m_renderWindow.draw(gHexagon);
}
