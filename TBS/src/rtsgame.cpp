#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <utility>
#include "localization.hpp"
#include "rtsgame.hpp"

#define ASSET_DIR "..\\Assets\\"

RTSGame::RTSGame(sf::RenderWindow &_renderWindow)
	: m_totalSeconds(0.0f),
	m_renderWindow(_renderWindow),
	m_lastFPSUpdate(-3e20f)
{
}

// Initialize the game
void RTSGame::Initialize()
{
	// Load font
	if (!m_fntArial.loadFromFile(ASSET_DIR "Fonts\\arial.ttf"))
	{
		std::puts(_("Could not load arial.ttf font file."));
		m_renderWindow.close();
		return;
	}

	// Set FPS counter location
	m_txtFPS.setFont(m_fntArial);
	m_txtFPS.setCharacterSize(11);
	m_txtFPS.setColor(sf::Color::White);
	m_txtFPS.setPosition(10.0f, 10.0f);

	// Create single hexagon
	constexpr float radius = 50.0f;
	constexpr float outlineThickness = 2.0f;
	sf::ConvexShape hexagon(6);
	for (size_t i = 0; i < hexagon.getPointCount(); i++)
	{
		const float x = std::cosf((float)(M_PI / 3 * i + M_PI_2)) * radius;
		const float y = std::sinf((float)(M_PI / 3 * i + M_PI_2)) * radius;
		hexagon.setPoint(i, sf::Vector2f(x, y));
	}
	hexagon.setPosition(sf::Vector2f((sf::Vector2f)m_renderWindow.getSize() * 0.5f));
	hexagon.setFillColor(sf::Color(0x888888FF));
	hexagon.setOutlineColor(sf::Color::White);
	hexagon.setOutlineThickness(outlineThickness);
	// Create a grid
	const float sin_60 = std::sinf((float)M_PI / 3);
	const float cos_60 = 0.5f;
	const sf::Vector2f x_axis_offset = sf::Vector2f(1, 0) * sin_60 * radius * 2.0f;
	const sf::Vector2f y_axis_offset = sf::Vector2f(cos_60, sin_60) * sin_60 * radius * 2.0f;
	for (short x = -3; x <= 3; x++) for (short y = -3; y <= 3; y++)
	{
		sf::ConvexShape tile = hexagon;
		tile.setPosition(hexagon.getPosition() + x_axis_offset * (float)x + y_axis_offset * (float)y);
		m_hexagons.push_back(std::move(tile));
	}
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
		// Close the program
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

	// Only update FPS 4 times per second max
	if (m_lastFPSUpdate + 0.1f < m_totalSeconds)
	{
		m_lastFPSUpdate = m_totalSeconds;
		auto text(std::string("FPS: ") + std::to_string((int)(1.0f / _deltaSeconds)));
		m_txtFPS.setString(text);
	}

	// Jiggle the hexagon
	//m_hexagon.rotate(std::sinf(m_totalSeconds) / 4);
} // Game::Tick

// Called after every tick to render the scene
void RTSGame::Render()
{
	// Render logic
	//m_renderWindow.draw(m_hexagon);
	for (auto tile : m_hexagons)
	{
		m_renderWindow.draw(tile);
	}

	// Draw FPS
	m_renderWindow.draw(m_txtFPS);
} // Game::Render
