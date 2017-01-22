#ifndef GOAL_H
#define GOAL_H

#include <SFML\Graphics.hpp>

class Goal {
public:
	Goal();
	void init(sf::Texture &texture, sf::Vector2f position);
	void render(sf::RenderWindow & window);
	sf::Vector2f getPosition();
	float getRadius();
private:
	const float SCALE = 1.f;
	float m_radius;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_position;
};

#endif

