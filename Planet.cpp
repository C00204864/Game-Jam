#include "Planet.h"

Planet::Planet(sf::Texture &texture)
	: m_radius(5.0f), m_planetTexture(texture)
{
	m_planetSprite.setTexture(m_planetTexture);
	m_planetSprite.setPosition(m_position);
	// Devide the radius of the planet by some magic number
	float scale = m_radius * RADIUS_TO_MASS;
	m_planetSprite.setScale(scale, scale);
}

Planet::Planet(sf::Texture &texture, sf::Vector2f position, float radius)
	: m_position(position), m_radius(radius), m_planetTexture(texture)
{
	m_planetSprite.setTexture(m_planetTexture);
	m_planetSprite.setPosition(m_position);
	// Devide the radius of the planet by some magic number
	float scale = m_radius;
	m_planetSprite.setScale(scale, scale);
	sf::FloatRect spriteRect = m_planetSprite.getLocalBounds();
	m_planetSprite.setOrigin(spriteRect.width / 2.0f, spriteRect.width / 2.0f);
}

sf::Vector2f Planet::GetPosition()
{
	return m_position;
}

float Planet::GetRadius()
{
	return m_radius;
}

float Planet::GetMass()
{
	return m_radius * RADIUS_TO_MASS;
}

void Planet::update(double dt)
{

}

void Planet::render(sf::RenderWindow &window)
{
	window.draw(m_planetSprite);
}