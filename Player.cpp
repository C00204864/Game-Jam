#include "Player.h"

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
	m_sprite.scale(sf::Vector2f(0.05, 0.05));
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2.f, m_sprite.getLocalBounds().height / 2.f);
	playerState = Play;
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
			m_fuel -= 20 * secondsSinceLastUpdate;
		}
		m_velocity += m_acceleration * secondsSinceLastUpdate; // v = u + at
		m_position += m_velocity * secondsSinceLastUpdate + m_acceleration * 0.5f * secondsSinceLastUpdate; //s = ut + 0.5at²
		m_sprite.setPosition(m_position);
		m_sprite.setRotation(m_rotation);

		m_fuelUI.update(m_fuel);

		break;
	}

	//std::cout << m_fuel << std::endl;

}

void Player::render(sf::RenderWindow &window)
{
	window.draw(m_sprite);
	m_fuelUI.render(window);
}

sf::Sprite Player::getSprite()
{
	return m_sprite;
}

void Player::checkGravity()
{
	//sf::Vector2f planetPos = planetIn.getPosition();
	//float planetMass = planetIn.get
	//float distance = getDistance(m_position, planetPos)
	//float accelerationMagnitude = (GRAVITATIONAL_CONSTANT * planetMass) / distance;
	//sf::Vector2 forceAdded = ((planetPos - m_position) / distance) * accelerationMagnitude;
	//m_acceleration += forceAdded;
	
		//For convenience space ship has a mass of ONE meaning that in F = MA --> F = A
		//Gonna drop some maths on yo ass
		/*
		F = GMm
		    ---
		    d²
		but...
		F = ma
		this implies...
	 -> ma = GMm
		     ---
		      d²
	 -> a = GM
		    ---
		    d²
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
	m_position = sf::Vector2f(0, 0);
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