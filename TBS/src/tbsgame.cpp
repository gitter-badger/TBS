#include "header.hpp"
#include "localization.hpp"
#include "tbsgame.hpp"
#include "input.hpp"

TBSGame::TBSGame(sf::RenderWindow &_renderWindow)
	: m_totalSeconds(0.0f),
	m_renderWindow(_renderWindow),
	m_lastFPSUpdate(-3e20f)
{
}

// Initialize the game
void TBSGame::Initialize()
{
	// Load font
	if (!m_fntArial.loadFromFile(ASSET_DIR "Fonts\\arial.ttf"))
	{
		std::puts(_("Could not load arial.ttf font file."));
		m_renderWindow.close();
		return;
	}

	// Bind key actions
	InputListener::Bind(sf::Keyboard::Escape, InputTriggers::Press, [&]() -> bool {
		// Close the game when pressing Escape
		m_renderWindow.close();
		return true;
	});

	// Set FPS counter location
	m_txtFPS.setFont(m_fntArial);
	m_txtFPS.setCharacterSize(11);
	m_txtFPS.setColor(sf::Color::White);
	m_txtFPS.setPosition(10.0f, 10.0f);

	// Create a grid
	const float sin_60 = std::sinf((float)M_PI / 3);
	const float cos_60 = 0.5f;
	constexpr float radius = 50.0f;
	const sf::Vector2f x_axis_offset = sf::Vector2f(1, 0) * sin_60 * radius * 2.0f;
	const sf::Vector2f y_axis_offset = sf::Vector2f(cos_60, sin_60) * sin_60 * radius * 2.0f;
	const auto center = sf::Vector2f(m_renderWindow.getSize().x / 2.0f, m_renderWindow.getSize().y / 2.0f);
	for (short x = -3; x <= 3; x++) for (short y = -3; y <= 3; y++)
	{
		m_grid.push_back(Tile(center + x_axis_offset * (float)x + y_axis_offset * (float)y));
	}
} // Game::Initialize

// Called when the mouse has moved
// @param _x        Screen position of the cursor
// @param _y        Screen position of the cursor
void TBSGame::MouseMove(int, int)
{
} // Game::MouseMove

// Called when a mouse button is pressed
// @param _button   The pressed button
// @param _x        Screen position of the cursor
// @param _y        Screen position of the cursor
void TBSGame::MouseDown(sf::Mouse::Button _button, int, int)
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
void TBSGame::MouseUp(sf::Mouse::Button _button, int, int)
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
void TBSGame::MouseWheelScrolled(int)
{

} // Game::MouseWheelScrolled

// Called every frame
// @param _deltaSeconds  The timespan since the last call
void TBSGame::Tick(float _deltaSeconds)
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
void TBSGame::Render()
{
	// Render logic
	//m_renderWindow.draw(m_hexagon);
	for (auto tile : m_grid)
	{
		m_renderWindow.draw(tile);
	}

	// Draw FPS
	m_renderWindow.draw(m_txtFPS);
} // Game::Render
