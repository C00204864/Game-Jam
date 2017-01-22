#include "FuelPickUp.h"

FuelPickUp::FuelPickUp(sf::Texture &texture, sf::Vector2f &position)
	: fuelTexture(texture), fuelPosition(position), m_pickedUp(false)
{
	fuelSprite.setTexture(fuelTexture);
	fuelSprite.setOrigin(fuelSprite.getLocalBounds().width / 2.0f, fuelSprite.getLocalBounds().height / 2.0f);
	fuelSprite.setPosition(fuelPosition);
	fuelSprite.setScale(0.5f, 0.5f);
}

void FuelPickUp::update(sf::Vector2f &position)
{
	m_rotation += 5.0f;
	fuelSprite.setRotation(m_rotation);

	sf::Vector2f direction = fuelPosition - position;
	float distance = sqrtf(direction.x*direction.x + direction.y*direction.y);
	 
	if (distance < 10.0f)
	{
		m_collided = true;
	}
}

void FuelPickUp::render(sf::RenderWindow &window)
{
	if(!m_pickedUp)
		window.draw(fuelSprite);
}

bool FuelPickUp::isCollided()
{
	return m_collided;
}

float FuelPickUp::GetSpriteWidth()
{
	return (((fuelSprite.getGlobalBounds().width) / 2.f));
}

void FuelPickUp::reset()
{
	m_pickedUp = false;
}