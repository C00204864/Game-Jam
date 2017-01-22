#ifndef HELPSCREEN_H
#define HELPSCREEN_H

#include <SFML\Graphics.hpp>
#include <string>

class HelpScreen {
public:
	HelpScreen(std::string, float, float);
	void update();
	void render(sf::RenderWindow &);
	bool returnToMenu();
	void reset();
private:
	bool m_returnToMenu;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

#endif

