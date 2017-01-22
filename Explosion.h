#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <string>
#include <iostream>
#include <SFML\Graphics.hpp>

class Explosion {
public:
	Explosion(std::string);
	void update();
	void render(sf::RenderWindow &);
	void setActive(sf::Vector2f);
	bool getState();
private:
	int m_spriteNumber;
	const int DURATION_OF_FRAMES = 2;
	const int READ_INCREMENT = 92;
	const int TEXTURE_RECT_SIZE = 89;
	const int CELLS_OF_ARRAY = 10;
	const float SCALE = 3.f;
	sf::Texture m_texture;
	sf::Sprite m_sprites[10];
	bool m_active;
};

#endif
