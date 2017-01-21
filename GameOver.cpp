#include "GameOver.h"

GameOver::GameOver()
{
	if (!m_backgroundTexture.loadFromFile("Resources/Backgrounds/Space_Nova.jpg"))
	{
		std::string s("Error loading GameOver Texture at Resources/Backgrounds/Space_Nova.jpg");
		throw std::exception(s.c_str());
	}

	if (!m_buttonTextures[0].loadFromFile("Resources/Buttons/Retry_Button.png"))
	{
		std::string s("Error loading GameOver Texture at Resources/Buttons/Retry_Button.png");
		throw std::exception(s.c_str());
	}

	if (!m_buttonTextures[1].loadFromFile("Resources/Buttons/Quit_Button.png"))
	{
		std::string s("Error loading GameOver Texture at Resources/Buttons/Quit_Button.png");
		throw std::exception(s.c_str());
	}

	init();
	fadeIn = true;
}

GameOver::~GameOver()
{
	std::cout << "Destructing GameOver" << std::endl;
}

void GameOver::update()
{
	timer++;
	mouse = currentMouse.getPosition();

	if (fadeIn)
	{
		screenFadeIn();
	}
	if (fadeOut)
	{
		screenFadeOut();
	}

	
	
	for (int i = 0; i < numButtons; i++)
	{
		if ((mouse.x >= m_buttonPositions[i].x && mouse.x <= m_buttonPositions[i].x + m_buttonWidth) &&
			(mouse.y >= m_buttonPositions[i].y && mouse.y <= m_buttonPositions[i].y + m_buttonHeight))
		{
			if (currentMouse.isButtonPressed(sf::Mouse::Left) &&
				!previousMouse)
			{
				m_buttons[i].setScale(2.5f, 2.5f);
				if (i == 0)
				{
					quitPressed = true;
				}
				previousMouse = true;
			}
			else
			{
				previousMouse = false;
			}
			currentHighlighted = i;
		}
		else
		{
			m_buttons[i].setScale(2.0f, 2.0f);
		}
	}

	keyboardInput();

	if (quitPressed)
	{
		screenFadeOut();
	}
	m_buttons[currentHighlighted].setScale(2.5f, 2.5f);
}

void GameOver::render(sf::RenderWindow &m_window)
{
	m_window.draw(m_backgroundSprite);
	for (int i = 0; i < 2; i++)
	{
		m_window.draw(m_buttons[i]);
	}
}

void GameOver::screenFadeIn()
{
	if (m_colour.a + m_alphaChange > MAX_ALPHA)
	{
		fadeIn = false;
	}
	else
	{
		m_colour.a += m_alphaChange;
	}
	m_backgroundSprite.setColor(m_colour);
	for (int i = 0; i < 2; i++)
	{
		m_buttons[i].setColor(m_colour);
	}
	
}

void GameOver::screenFadeOut()
{
	if (m_colour.a - m_alphaChange < 0)
	{
		fadeOut = false;
		animationOver = true;
	}
	else
	{
		m_colour.a -= m_alphaChange;
	}
	m_backgroundSprite.setColor(m_colour);
	for (int i = 0; i < 2; i++)
	{
		m_buttons[i].setColor(m_colour);
	}
}

bool GameOver::quitGame()
{
	return animationOver;
}

void GameOver::keyboardInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !m_keyPressedLeft)
	{
		if (currentHighlighted > 0)
		{
			currentHighlighted--;
		}
		else
		{
			currentHighlighted = 0;
		}
		m_keyPressedLeft = true;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !m_keyPressedRight)
	{
		if (currentHighlighted < numButtons - 1)
		{
			currentHighlighted++;
		}
		else
		{
			currentHighlighted = numButtons - 1;
		}
		m_keyPressedRight = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if (currentHighlighted == 0)
		{
			//restart Game;
		}
		else
		{
			quitPressed = true;
		}
	}

	if (timer > 30)
	{
		m_keyPressedLeft = false;
		m_keyPressedRight = false;
		timer = 0;
	}
}

void GameOver::init()
{
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);

	sf::Color tempColour;
	tempColour = m_backgroundSprite.getColor();

	m_colour.r = tempColour.r;
	m_colour.g = tempColour.g;
	m_colour.b = tempColour.b;
	m_colour.a = 0;

	m_backgroundSprite.setColor(m_colour);
	for (int i = 0; i < 2; i++)
	{
		m_buttons[i].setTexture(m_buttonTextures[i]);
		m_buttons[i].setPosition(300 + ((200 * (i + 1)) * m_buttons[0].getScale().x), 1000);
		m_buttons[i].setColor(m_colour);
		m_buttons[i].setScale(2.0f, 2.0f);
		m_buttonPositions[i] = static_cast<sf::Vector2i>(m_buttons[i].getPosition());
	}
}
