#include "Background.h"

Background::Background()
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int time = aTime->tm_hour;

	if (time < 12)	// Early day texture
	{
		if (!m_backgroundTexture.loadFromFile("Resources/Backgrounds/Space_Nova.jpg"))
		{
			std::cout << "GAME:: background texture [Super_Nova] not loaded" << std::endl;
		}
	}
	else if(time < 18)	// Evening day texture
	{
		if (!m_backgroundTexture.loadFromFile("Resources/Backgrounds/Space_Fire.jpg"))
		{
			std::cout << "GAME:: background texture [Space_Fire] not loaded" << std::endl;
		}
	}
	else if (time < 24)	// Night time texture 
	{
		if (!m_backgroundTexture.loadFromFile("Resources/Backgrounds/BlackHole.jpg"))
		{
			std::cout << "GAME:: background texture [BlackHole] not loaded" << std::endl;
		}
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
}

void Background::render(sf::RenderWindow &window)
{
	window.draw(m_backgroundSprite);
}