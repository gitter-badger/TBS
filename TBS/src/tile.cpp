#include "header.hpp"
#include "tile.h"

Tile::Tile(sf::Vector2f _position)
	: m_sprite(new sf::ConvexShape(6))
{
	sf::ConvexShape *hexagon = static_cast<sf::ConvexShape*>(m_sprite);
	// Create single hexagon
	constexpr float radius = 50.0f;
	constexpr float outlineThickness = 2.0f;
	for (size_t i = 0; i < hexagon->getPointCount(); i++)
	{
		const float x = std::cosf((float)(M_PI / 3 * i + M_PI_2)) * radius;
		const float y = std::sinf((float)(M_PI / 3 * i + M_PI_2)) * radius;
		hexagon->setPoint(i, sf::Vector2f(x, y));
	}
	hexagon->setPosition(_position);
	hexagon->setFillColor(sf::Color(0x888888FF));
	hexagon->setOutlineColor(sf::Color::White);
	hexagon->setOutlineThickness(outlineThickness);
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	target.draw(*m_sprite);
}
