#ifndef FUEL_PICK_UP_H
#define FUEL_PICK_UP_H

#include <SFML\Graphics.hpp>

class FuelPickUp
{
public:
	FuelPickUp(sf::Texture &texture, sf::Vector2f &position);

	void update(sf::Vector2f &position);
	void render(sf::RenderWindow &window);
	bool isCollided();
	sf::Vector2f fuelPosition;

private:
	sf::Texture &fuelTexture;
	sf::Sprite fuelSprite;
	float m_rotation;
	bool m_collided;
};

#endif 