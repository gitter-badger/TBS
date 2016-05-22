#pragma once

#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable
{
public:
	Tile(sf::Vector2f _position);
	~Tile() = default;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	sf::Drawable *m_sprite;

private:
	sf::Vector2i m_coordinate;
};
