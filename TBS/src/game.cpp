#include "game.hpp"
#include "tbsgame.hpp"

// Constructor
IGame::IGame(sf::RenderWindow &_renderWindow)
	: m_TBSGame(new TBSGame(_renderWindow))
{
}

// Forward function calls to m_TBSGame
void IGame::Initialize() { m_TBSGame->Initialize(); }
void IGame::KeyPressed(sf::Keyboard::Key _keyCode) { m_TBSGame->KeyPressed(_keyCode); }
void IGame::KeyReleased(sf::Keyboard::Key _keyCode) { m_TBSGame->KeyReleased(_keyCode); }
void IGame::MouseMove(int _x, int _y) { m_TBSGame->MouseMove(_x, _y); }
void IGame::MouseDown(sf::Mouse::Button _button, int _x, int _y) { m_TBSGame->MouseDown(_button, _x, _y); }
void IGame::MouseUp(sf::Mouse::Button _button, int _x, int _y) { m_TBSGame->MouseUp(_button, _x, _y); }
void IGame::MouseWheelScrolled(int _delta) { m_TBSGame->MouseWheelScrolled(_delta); }
void IGame::Tick(float _deltaSeconds) { m_TBSGame->Tick(_deltaSeconds); }
void IGame::Render() { m_TBSGame->Render(); }
