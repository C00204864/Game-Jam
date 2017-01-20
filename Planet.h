#ifndef PLANET_H
#define PLANET_H

#include <SFML\Graphics.hpp>
#include <iostream>

class Planet
{
public:
	Planet();
	void update(double dt);
	void render(sf::RenderWindow &window);

private:
	sf::Texture m_planetTexture;
	sf::Sprite m_planetSprite;
};

#endif