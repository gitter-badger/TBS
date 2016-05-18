#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include "rtsgame.hpp"

RTSGame::RTSGame(sf::RenderWindow &_renderWindow)
	: m_totalSeconds(0.0f),
	m_renderWindow(_renderWindow)
{
}

// Initialize the game
void RTSGame::Initialize()
{
	// Create hexagon
	constexpr const float radius = 150.0f;
	constexpr const float outlineThickness = 10.0f;
	m_hexagon.setPointCount(6);
	for (size_t i = 0; i < m_hexagon.getPointCount(); i++)
	{
		const float x = std::cosf((float)M_PI * 2 / m_hexagon.getPointCount() * i) * radius;
		const float y = std::sinf((float)M_PI * 2 / m_hexagon.getPointCount() * i) * radius;
		m_hexagon.setPoint(i, sf::Vector2f(x, y));
	}
	m_hexagon.setPosition(sf::Vector2f((sf::Vector2f)m_renderWindow.getSize() * 0.5f));
	m_hexagon.setFillColor(sf::Color(0x888888FF));
	m_hexagon.setOutlineColor(sf::Color::White);
	m_hexagon.setOutlineThickness(outlineThickness);
} // Game::Initialize

  // Called when a keyboard key is pressed
  // @param _KeyCode	The key that was pressed
void RTSGame::KeyPressed(sf::Keyboard::Key _keyCode)
{
	switch (_keyCode)
	{
	case sf::Keyboard::Unknown: // Caps Lock, Scroll Lock, Num Lock
		std::puts("An unknown key has been pressed!");
		break;

	case sf::Keyboard::Escape:
		m_renderWindow.close();
		break;

	default:
		std::printf("Code of key being pressed: %d.\n", _keyCode);
		break;
	} // switch _keyCode
} // Game::KeyPressed

  // Called when a keyboard key is released
  // @param _KeyCode	The key that was released
void RTSGame::KeyReleased(sf::Keyboard::Key _keyCode)
{
	switch (_keyCode)
	{
	case sf::Keyboard::Unknown:
		// Unknown key has been released
		break;
	default:
		break;
	} // switch _keyCode
} // Game::KeyReleased

  // Called when the mouse has moved
  // @param _x        Screen position of the cursor
  // @param _y        Screen position of the cursor
void RTSGame::MouseMove(int, int)
{
} // Game::MouseMove

  // Called when a mouse button is pressed
  // @param _button   The pressed button
  // @param _x        Screen position of the cursor
  // @param _y        Screen position of the cursor
void RTSGame::MouseDown(sf::Mouse::Button _button, int, int)
{
	// Switch on the pressed button
	switch (_button)
	{
	case sf::Mouse::Left:
		break;
	case sf::Mouse::Right:
		break;
	case sf::Mouse::Middle:
		break;
	}
} // Game::MouseDown

  // Called when a mouse button is released
  // @param _button   The released button
  // @param _x        Screen position of the cursor
  // @param _y        Screen position of the cursor
void RTSGame::MouseUp(sf::Mouse::Button _button, int, int)
{
	// Switch on the released button
	switch (_button)
	{
	case sf::Mouse::Left:
		break;
	case sf::Mouse::Right:
		break;
	case sf::Mouse::Middle:
		break;
	}
} // Game::MouseUp

  // Called when the mouse wheel is scrolled
  // @param _delta    The number of ticks
void RTSGame::MouseWheelScrolled(int)
{

} // Game::MouseWheelScrolled

  // Called every frame
  // @param _deltaSeconds  The timespan since the last call
void RTSGame::Tick(float _deltaSeconds)
{
	// Increase the game time
	m_totalSeconds += _deltaSeconds;

	// Jiggle the hexagon
	m_hexagon.rotate(std::sinf(m_totalSeconds) / 4);
} // Game::Tick

  // Called after every tick to render the scene
void RTSGame::Render()
{
	// Render logic
	m_renderWindow.draw(m_hexagon);
} // Game::Render
