#include "Goal.h"

Goal::Goal() {}

void Goal::init(sf::Texture &textureIn, sf::Vector2f position)
{
	m_texture = textureIn;
	m_position = position;
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(sf::Vector2f(SCALE, SCALE));
	m_sprite.setPosition(m_position);
	sf::FloatRect spriteRect = m_sprite.getLocalBounds();
	m_sprite.setOrigin(spriteRect.width / 2.f, spriteRect.width / 2.f);
	m_radius = (m_sprite.getGlobalBounds().width) / (2.f);
}

void Goal::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

sf::Vector2f Goal::getPosition()
{
	return m_position;
}

float Goal::getRadius()
{
	return m_radius;
}