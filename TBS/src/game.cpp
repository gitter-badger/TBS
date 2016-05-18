#include "game.hpp"
#include "rtsgame.hpp"

// Constructor
IGame::IGame(sf::RenderWindow &_renderWindow)
	: m_imp(new RTSGame(_renderWindow))
{
} // Game::Game

// Initialize the game
void IGame::Initialize()
{
	m_imp->Initialize();
} // Game::Initialize

// Called when a keyboard key is pressed
// @param _KeyCode	The key that was pressed
void IGame::KeyPressed(sf::Keyboard::Key _keyCode)
{
	m_imp->KeyPressed(_keyCode);
} // Game::KeyPressed

// Called when a keyboard key is released
// @param _KeyCode	The key that was released
void IGame::KeyReleased(sf::Keyboard::Key _keyCode)
{
	m_imp->KeyReleased(_keyCode);
} // Game::KeyReleased

// Called when the mouse has moved
// @param _x        Screen position of the cursor
// @param _y        Screen position of the cursor
void IGame::MouseMove(int _x, int _y)
{
	m_imp->MouseMove(_x, _y);
} // Game::MouseMove

// Called when a mouse button is pressed
// @param _button   The pressed button
// @param _x        Screen position of the cursor
// @param _y        Screen position of the cursor
void IGame::MouseDown(sf::Mouse::Button _button, int _x, int _y)
{
	m_imp->MouseDown(_button, _x, _y);
} // Game::MouseDown

// Called when a mouse button is released
// @param _button   The released button
// @param _x        Screen position of the cursor
// @param _y        Screen position of the cursor
void IGame::MouseUp(sf::Mouse::Button _button, int _x, int _y)
{
	m_imp->MouseUp(_button, _x, _y);
} // Game::MouseUp

// Called when the mouse wheel is scrolled
// @param _delta    The number of ticks, can be negative
void IGame::MouseWheelScrolled(int _delta)
{
	m_imp->MouseWheelScrolled(_delta);
} // Game::MouseWheelScrolled

// Called every frame
// @param _deltaSeconds  The timespan since the last call
void IGame::Tick(float _deltaSeconds)
{
	m_imp->Tick(_deltaSeconds);
} // Game::Tick

// Called after every tick to render the scene
void IGame::Render()
{
	m_imp->Render();
} // Game::Render
