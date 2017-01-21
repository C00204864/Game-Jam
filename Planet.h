#ifndef PLANET_H
#define PLANET_H

#include <SFML\Graphics.hpp>
#include <iostream>

class Planet
{
public:
	Planet(sf::Texture &texture);
	Planet(sf::Texture &texture, sf::Vector2f position, float radius);
	void update(double dt);
	void render(sf::RenderWindow &window);

	sf::Vector2f GetPosition();
	float GetRadius();

private:
	sf::Texture &m_planetTexture;
	sf::Sprite m_planetSprite;
	sf::Vector2f m_position;
	float m_radius;
};

#endif