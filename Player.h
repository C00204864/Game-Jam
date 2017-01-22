#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <cmath>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "FuelUI.h"
#include "XboxController.h"
#include "Explosion.h"

enum PlayerState { Play, Dead };

class Player {
public:
	Player();
	Player(sf::Vector2f, sf::Vector2f, float, std::string, sf::Vector2u windowSize);
	void update(double dt);
	void render(sf::RenderWindow &window);
	sf::Sprite getSprite();
	void checkGravity(sf::Vector2f planetPosition, float planetMass);
	float getDistance(sf::Vector2f, sf::Vector2f);
	void increaseRotation();
	void decreaseRotation();
	float getFuel();
	sf::Vector2f getPosition();
	void reset();
	void reset(sf::Vector2f, float);
	void checkCollisionPlanet(sf::Vector2f planetPosition, float planetRadius);
	bool checkCollisionFuelItem(sf::Vector2f planetPosition, float planetRadius);
	PlayerState playerState;
	bool m_alive;

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	sf::Vector2f thrustVector;
	float m_radiusOfImpact;
	bool renderExhaust;
	float m_rotation;
	float m_fuel;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Texture m_exhaustTexture;
	sf::Sprite m_exhaustSprite;
	const float ROTATION_MAGNITUDE = 5.0f;
	const float LIFTOFF_VELOCITY_MAGNITUDE = 100.f;
	const float THRUST_PER_SECOND = 1000.0f;
	const float DEG_TO_RAD = (3.14f / 180.f);
	FuelUI m_fuelUI;
	XboxController xboxController;
	Explosion deathExplosion;
};

#endif

