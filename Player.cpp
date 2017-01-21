#include "Player.h"

#define GRAVITATIONAL_CONSTANT 200000.0

//Player Default Constructor
Player::Player() :
	m_position(),
	m_velocity(),
	m_rotation(0),
	m_fuelUI(sf::Vector2f(100.0f, 100.0f))
{}

//Player Overloaded constructor !---(THE ONE YOU SHOULD USE)---!
Player::Player(sf::Vector2f positionIn, sf::Vector2f velocityIn, float rotationIn, std::string filePathIn, sf::Vector2u windowSize): 
	m_position(positionIn),
	m_velocity(velocityIn),
	m_rotation(rotationIn),
	m_fuelUI(sf::Vector2f(100.0f, windowSize.y - 400.0f))
{
	m_texture.loadFromFile(filePathIn);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.scale(sf::Vector2f(0.25f, 0.25f));
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2.0f, m_sprite.getLocalBounds().height / 2.0f);
	playerState = Play;

	if (!m_exhaustTexture.loadFromFile("Resources/Player/SpaceShipExhaust.png"))
	{
		std::cout << "PLAYER:: Exhaust image not loaded" << std::endl;
	}

	m_exhaustSprite.setTexture(m_exhaustTexture);
	m_exhaustSprite.setPosition(m_position);
	m_exhaustSprite.setOrigin(m_sprite.getLocalBounds().width / 2.0f, m_sprite.getLocalBounds().height / 2.0f);
	m_exhaustSprite.setScale(sf::Vector2f(0.25f, 0.25f));
}

void Player::update(double timeSinceLastUpdate)
{
	float secondsSinceLastUpdate = timeSinceLastUpdate / 1000.0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		decreaseRotation();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		increaseRotation();
	}
	switch (playerState)
	{
	case Start:
		
		break;
	case Play:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_fuel > 0)
		{
			thrustVector.x = std::cos(m_rotation * DEG_TO_RAD) * THRUST_PER_SECOND;
			thrustVector.y = std::sin(m_rotation * DEG_TO_RAD) * THRUST_PER_SECOND;
			m_velocity += thrustVector * secondsSinceLastUpdate;
			//m_fuel -= 20 * secondsSinceLastUpdate;
			renderExhaust = true;
		}
		else
			renderExhaust = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			reset();
		}

		m_velocity += m_acceleration * secondsSinceLastUpdate; // v = u + at
		m_position += m_velocity * secondsSinceLastUpdate + m_acceleration * 0.5f * secondsSinceLastUpdate; //s = ut + 0.5at�
		m_sprite.setPosition(m_position);
		m_sprite.setRotation(m_rotation);
		m_exhaustSprite.setPosition(m_position);
		m_exhaustSprite.setRotation(m_rotation);

		m_fuelUI.update(m_fuel);

		break;
	}

	//std::cout << m_fuel << std::endl;

}

void Player::render(sf::RenderWindow &window)
{
	window.draw(m_sprite);
	m_fuelUI.render(window);
	if(renderExhaust)
		window.draw(m_exhaustSprite);
}

sf::Sprite Player::getSprite()
{
	return m_sprite;
}

void Player::checkGravity(sf::Vector2f planetPosition, float mass)
{
	//m_acceleration = sf::Vector2f();
	sf::Vector2f planetPos = planetPosition;
	float planetMass = mass;
	float distance = getDistance(m_position, planetPos);
	float accelerationMagnitude = (GRAVITATIONAL_CONSTANT * planetMass) / (distance * distance);
	sf::Vector2f forceAdded = ((planetPos - m_position) / distance) * accelerationMagnitude;
	m_acceleration += forceAdded;
	
		//For convenience space ship has a mass of ONE meaning that in F = MA --> F = A
		//Gonna drop some maths on yo ass
		/*
		F = GMm
		    ---
		    d�
		but...
		F = ma
		this implies...
	 -> ma = GMm
		     ---
		      d�
	 -> a = GM
		    ---
		    d�
		*/
}

float Player::getDistance(sf::Vector2f vecOne, sf::Vector2f vecTwo)
{
	float x1 = vecOne.x;
	float x2 = vecTwo.x;
	float y1 = vecOne.y;
	float y2 = vecTwo.y;
	return static_cast<float>(std::sqrt((x2  -x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void Player::increaseRotation()
{
	m_rotation += ROTATION_MAGNITUDE;
}

void Player::decreaseRotation()
{
	m_rotation -= ROTATION_MAGNITUDE;
}

float Player::getFuel()
{
	return m_fuel;
}

void Player::reset()
{
	m_position = sf::Vector2f(400.0f, 400.0f);
	m_velocity = sf::Vector2f(0, 0);
	m_acceleration = sf::Vector2f(0, 0);
	m_rotation = 0;
	m_fuel = 100;
}

void Player::reset(sf::Vector2f positionIn, float rotationIn)
{
	m_position = positionIn;
	m_velocity = sf::Vector2f(0, 0);
	m_acceleration = sf::Vector2f(0, 0);
	m_rotation = rotationIn;
	m_fuel = 100;
}