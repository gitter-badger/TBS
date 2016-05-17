#define _USE_MATH_DEFINES
#include <cmath>
#include "game.hpp"

// Temporary globals
static sf::ConvexShape gHexagon;

Game::Game(sf::RenderWindow &_renderWindow)
	: m_renderWindow(_renderWindow)
	, m_totalSeconds(0.0f)
{
} // Game::Game

// Initialize the game
void Game::Initialize()
{
	// Create hexagon
	constexpr const float radius = 150.0f;
	constexpr const float outlineThickness = 10.0f;
	gHexagon.setPointCount(6);
	for (size_t i = 0; i < gHexagon.getPointCount(); i++)
	{
		const float x = std::cosf((float)M_PI * 2 / gHexagon.getPointCount() * i) * radius;
		const float y = std::sinf((float)M_PI * 2 / gHexagon.getPointCount() * i) * radius;
		gHexagon.setPoint(i, sf::Vector2f(x, y));
	}
	gHexagon.setPosition(sf::Vector2f((sf::Vector2f)m_renderWindow.getSize() * 0.5f));
	gHexagon.setFillColor(sf::Color(0x888888FF));
	gHexagon.setOutlineColor(sf::Color::White);
	gHexagon.setOutlineThickness(outlineThickness);
} // Game::Initialize

// Called when a keyboard key is pressed
// @param _KeyCode	The key that was pressed
void Game::KeyPressed(sf::Keyboard::Key _keyCode)
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
} // Game::KeyReleased

// Called when the mouse has moved
// @param _x        Screen position of the cursor
// @param _y        Screen position of the cursor
void Game::MouseMove(int _x, int _y)
{
	// Update the stored mouse position
	m_mousePosition.x = _x;
	m_mousePosition.y = _y;
} // Game::MouseMove

// Called when a mouse button is pressed
// @param _button   The pressed button
// @param _x        Screen position of the cursor
// @param _y        Screen position of the cursor
void Game::MouseDown(sf::Mouse::Button _button, int, int)
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
} // Game::MouseDown

// Called when a mouse button is released
// @param _button   The released button
// @param _x        Screen position of the cursor
// @param _y        Screen position of the cursor
void Game::MouseUp(sf::Mouse::Button _button, int, int)
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
} // Game::MouseUp

// Called when the mouse wheel is scrolled
// @param _delta    The number of ticks
void Game::MouseWheelScrolled(int)
{

} // Game::MouseWheelScrolled

// Called every frame
// @param _deltaSeconds  The timespan since the last call
void Game::Tick(float _deltaSeconds)
{
	// Increase the game time
	m_totalSeconds += _deltaSeconds;

	// Jiggle the hexagon
	gHexagon.rotate(std::sinf(m_totalSeconds) / 4);
} // Game::Tick

// Called after every tick to render the scene
void Game::Render()
{
	// Render logic
	m_renderWindow.draw(gHexagon);
} // Game::Render
