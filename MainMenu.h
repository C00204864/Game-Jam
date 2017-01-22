#ifndef  MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>
#include "XboxController.h"
#include "FuelUI.h"

using namespace std;

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void update();
	void render(sf::RenderWindow & m_window);

	bool playPressed;
	bool quitePressed;
	bool optionsPressed;

protected:
	const int numButtons = 3;
	sf::Texture m_backgroundTexture;
	sf::Sprite  m_backgroudSprite;

	sf::Texture m_buttonTextures[3];
	sf::Sprite m_buttonSprites[3];

	sf::Mouse currentMouse;
	bool previousMouse;

	sf::Vector2i m_buttonPositions[3];
	sf::Vector2i mouse;
	int m_buttonWidth, m_buttonHeight;
	void init();

	bool m_buttonPressed;
	bool m_keyPressedUp;
	bool m_keyPressedDown;

	bool isHighlighted[3];
	int currentHighlighted = 0;

	int timer = 0;

	XboxController xboxController;

};

#endif // ! MAINMENU_H
