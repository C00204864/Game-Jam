#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include "HelpScreen.h"
#include <SFML\Graphics.hpp>
class OptionsMenu
{
public:
	OptionsMenu();
	~OptionsMenu();

	void startAnimation();
	void endAnimation();

	void update();
	void render(sf::RenderWindow &m_window);
	bool m_active;
	bool m_finished;
	bool helpPressed;
	bool leavePressed;

	HelpScreen help;

protected:
	sf::Mouse currentMouse;
	sf::Vector2i mouse;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	sf::Texture m_buttonTexture;
	sf::Sprite m_button;

	sf::Vector2i m_buttonPosition;

	int m_buttonWidth, m_buttonHeight;

	const float m_maxScaleH = 1.5f;
	const float m_maxScaleW = 1.5f;
	float m_currentScale;
	bool m_scalingIn;
	bool m_scalingOut;
	void scaleIn();
	void scaleOut();

	void mouseInput();
	void keyboardInput();
	void init();
};

#endif
