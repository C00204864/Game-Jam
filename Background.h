#ifndef BACKGROUND_H
#define BACKGROUND_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS		// Bad ass over here
#endif

#include <iostream>
#include <ctime>
#include <SFML\Graphics.hpp>

/*
	The background changes on the time of day... FEATURES!!!!
*/
class Background
{
public:
	Background();
	void render(sf::RenderWindow &window);

private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
};

#endif