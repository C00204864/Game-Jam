#ifndef SPLASH_H
#define SPLASH_H

#include <string>
#include <SFML\Graphics.hpp>

enum FadeState {FadeIn, FadeOut};

class Splash {
public:
	Splash(std::string, float, float);
	void update();
	void render(sf::RenderWindow & window);
	bool animationComplete();
private:
	void fadeIn();
	void fadeOut();
	FadeState fadeState;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Color m_color;
	bool m_animationComplete;
	const int ALPHA_CHANGE = 1;
	const int MAX_ALPHA = 255;
};

#endif
