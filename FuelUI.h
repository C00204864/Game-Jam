#ifndef FUELUI_H
#define FUELUI_H

#include <iostream>
#include <SFML\Graphics.hpp>

class FuelUI
{
public:
	FuelUI();
	FuelUI(sf::Vector2f pos);
	~FuelUI();

	sf::Vector2f getPosition();
	void loadTexture(std::string path);
	void setPosition(sf::Vector2f &pos);

	void update(float fuel);
	void render(sf::RenderWindow & window);

protected:
	sf::Vector2f m_pos;
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	sf::RectangleShape m_bar;

	float maxHeight;
	void initialiseSprite();
};

#endif