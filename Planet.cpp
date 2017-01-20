#include "Planet.h"

Planet::Planet()
{
	if (!m_planetTexture.loadFromFile("Resources/planet.png"))
	{
		std::cout << "Planet texture not loaded" << std::endl;
	}

	m_planetSprite.setTexture(m_planetTexture);
}

void Planet::update(double dt)
{

}

void Planet::render(sf::RenderWindow &window)
{
	window.draw(m_planetSprite);
}