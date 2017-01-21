#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include <string>
#include <cmath>
#include <iostream>

enum PlayerState {Start, Play, None};

class Player {
public:
	Player();
	Player(sf::Vector2f, sf::Vector2f, float, std::string);
	void update(double dt);
	void render(sf::RenderWindow &window);
	sf::Sprite getSprite();
	void checkGravity(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!include planet class and pass in a reference to planet or optionally an array
	float getDistance(sf::Vector2f, sf::Vector2f);
	void increaseRotation();
	void decreaseRotation();
	float getFuel();
	void reset();
	void reset(sf::Vector2f, float);
	PlayerState playerState;

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	sf::Vector2f thrustVector;
	float m_rotation;
	float m_fuel = 100.0f;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	const float ROTATION_MAGNITUDE = 5.0f;
	const float LIFTOFF_VELOCITY_MAGNITUDE = 100.f;
	const float THRUST_PER_SECOND = 100.0f;
	const float DEG_TO_RAD = (3.14f / 180.f);
};

#endif

