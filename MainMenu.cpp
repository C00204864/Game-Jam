#include "FuelUI.h"
#include "MainMenu.h"

MainMenu::MainMenu()
{

	if (!m_backgroundTexture.loadFromFile("Resources/Backgrounds/BlackHole.jpg"))
	{
		std::string s("Error loading MainMenu Texture at Resources/Backgrounds/BlackHole.jpg");
		throw std::exception(s.c_str());
	}

	if (!m_buttonTextures[0].loadFromFile("Resources/Buttons/Play_Button.png"))
	{
		std::string s("Error loading MainMenu Button Texture at Resources/Buttons/Play_Button.png");
		throw std::exception(s.c_str());
	}
	if (!m_buttonTextures[1].loadFromFile("Resources/Buttons/Options_Button.png"))
	{
		std::string s("Error loading MainMenu Button Texture at Resources/Buttons/Options_Button.png");
		throw std::exception(s.c_str());
	}
	if (!m_buttonTextures[2].loadFromFile("Resources/Buttons/Quit_Button.png"))
	{
		std::string s("Error loading MainMenu Button Texture at Resources/Buttons/Quit_Button.png");
		throw std::exception(s.c_str());
	}
	
	m_backgroudSprite.setTexture(m_backgroundTexture);

	for (int i = 0; i < numButtons; i++)
	{
		m_buttonSprites[i].setTexture(m_buttonTextures[i]);
	}

	init();
}

MainMenu::~MainMenu()
{
	std::cout << "destructing main menu" << std::endl;
}

void MainMenu::update()
{
	timer++;
	mouse = currentMouse.getPosition();
	for (int i = 0; i < numButtons; i++)
	{
		if ((mouse.x >= m_buttonPositions[i].x && mouse.x <= m_buttonPositions[i].x + m_buttonWidth) &&
			(mouse.y >= m_buttonPositions[i].y && mouse.y <= m_buttonPositions[i].y + m_buttonHeight))
		{
			isHighlighted[i] = true;
			if (currentMouse.isButtonPressed(sf::Mouse::Left) &&
				!previousMouse)
			{
				if (i == 0)
				{
					playPressed = true;
					/*m_buttonSprites[i].scale(5.0f, 5.0f);*/
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
			m_buttonSprites[i].setScale(2.0f, 2.0f);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !m_keyPressedUp)
	{
		if (currentHighlighted > 0)
		{
			currentHighlighted--;
		}
		else
		{
			currentHighlighted = 0;
		}
		m_keyPressedUp = true;
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !m_keyPressedDown)
	{
		if (currentHighlighted < numButtons - 1)
		{
			currentHighlighted++;
		}
		else
		{
			currentHighlighted = numButtons - 1;
		}
		m_keyPressedDown = true;
	}

	if (timer > 30)
	{
		m_keyPressedDown = false;
		m_keyPressedUp = false;
		timer = 0;
	}

	m_buttonSprites[currentHighlighted].setScale(2.5f, 2.5f);
	
}

void MainMenu::render(sf::RenderWindow &m_window)
{
	m_window.draw(m_backgroudSprite);
	for (int i = 0; i < numButtons; i++)
	{
		m_window.draw(m_buttonSprites[i]);
	}
}

void MainMenu::init()
{
	currentMouse.setPosition(sf::Vector2i(730, 800));

	m_backgroudSprite.setPosition(0, 0);
	for (int i = 0; i < numButtons; i++)
	{
		m_buttonSprites[i].setPosition(730, 800 + (i * 200));
		m_buttonSprites[i].setScale(2.0f, 2.0f);
		m_buttonPositions[i] = static_cast<sf::Vector2i>(m_buttonSprites[i].getPosition());
	}
	m_buttonWidth = m_buttonSprites[0].getTextureRect().width * m_buttonSprites[0].getScale().x;
	m_buttonHeight = m_buttonSprites[0].getTextureRect().height * m_buttonSprites[0].getScale().y;
	m_buttonPressed = false;

	currentHighlighted = 0;
}
