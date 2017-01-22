#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

class GameOver
{
public:
	GameOver();
	~GameOver();

	void update();
	void render(sf::RenderWindow &m_window);

	void screenFadeIn();
	void screenFadeOut();

	bool playAgain;
	bool quitGame();

	bool restartGame;
	
protected:
	const int numButtons = 2;

	void keyboardInput();
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	sf::Sprite m_buttons[2];
	sf::Texture m_buttonTextures[2];

	int m_buttonWidth, m_buttonHeight;
	sf::Vector2i m_buttonPositions[3];

	void init();

	bool isHighlighted;

	float m_fadeInTimeLimit = 5;
	const int MAX_ALPHA = 255;
	const int m_alphaChange = 3;

	bool fadeIn, fadeOut;
	bool quitPressed;
	bool animationOver;
	int currentHighlighted = 0;

	bool m_keyPressedLeft, m_keyPressedRight;
	int timer = 0;

	sf::Mouse currentMouse;
	sf::Vector2i mouse;
	sf::Color m_colour;
	bool previousMouse;
	
};

#endif
