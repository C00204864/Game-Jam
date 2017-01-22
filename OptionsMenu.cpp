#include "OptionsMenu.h"

OptionsMenu::OptionsMenu() :
	help("Resources/Ui/ControlScheme.png", 3840, 2160)
{
	if (!m_backgroundTexture.loadFromFile("Resources/Backgrounds/Options_Menu.jpg"))
	{
		std::string s("Error loading OptionsMenu Texture at Resources/Backgrounds/Space_Nova.jpg");
		throw std::exception(s.c_str());
	}

	if (!m_buttonTexture.loadFromFile("Resources/Buttons/Help_Button.png"))
	{
		std::string s("Error loading OptionsMenu Texture at Resources/Buttons/Help_Button.png");
		throw std::exception(s.c_str());
	}
	init();
}

OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::startAnimation()
{
		m_scalingIn = true;
		m_active = true;
		leavePressed = false;
		helpPressed = false;
}

void OptionsMenu::endAnimation()
{
	m_scalingIn = false;
	m_scalingOut = true;
}

void OptionsMenu::scaleIn()
{
	if (m_currentScale <= m_maxScaleW)
	{
		m_currentScale += 0.05f;
		if (m_currentScale <= 1.0f)
		{
			m_backgroundSprite.setScale(m_currentScale, 1.0f);
		}
		m_button.setScale(m_currentScale, 1.0f);
	}
	else
	{
		m_scalingIn = false;
	}
}

void OptionsMenu::scaleOut()
{
	if (m_currentScale >= 0)
	{
		m_currentScale -= 0.05f;
		if (m_backgroundSprite.getScale().x > 0)
		{
			m_backgroundSprite.setScale(m_currentScale - 0.5f, 1.0f);
		}
		m_button.setScale(m_currentScale, 1.0f);
	}
	else
	{
		m_scalingOut = false;
		m_finished = true;
		m_active = false;
	}
}

void OptionsMenu::mouseInput()
{
	mouse = currentMouse.getPosition();
	if ((mouse.x >= m_buttonPosition.x && mouse.x <= m_buttonPosition.x + m_buttonWidth) &&
		(mouse.y >= m_buttonPosition.y && mouse.y <= m_buttonPosition.y + m_buttonHeight))
	{
		m_button.setScale(sf::Vector2f(m_maxScaleH, m_maxScaleW));
		if (currentMouse.isButtonPressed(sf::Mouse::Left) & !helpPressed)
		{
			helpPressed = true;
		}
	}
	else
	{
		m_button.setScale(sf::Vector2f(m_maxScaleW, 1.0f));
	}
}

void OptionsMenu::keyboardInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !helpPressed)
	{
		helpPressed = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !leavePressed)
	{
		leavePressed = true;
		endAnimation();
	}
}

void OptionsMenu::init()
{
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setScale(sf::Vector2f(0.0f, 1.0f));
	m_backgroundSprite.setPosition(1500, 500);

	m_button.setTexture(m_buttonTexture);
	m_button.setScale(sf::Vector2f(0.0f, 2.0f));
	m_button.setPosition(1550, 700);

	m_buttonPosition = static_cast<sf::Vector2i>(m_button.getPosition());
	m_buttonWidth = m_button.getTextureRect().width * m_maxScaleW;
	m_buttonHeight = m_button.getTextureRect().height * m_maxScaleH;

	m_currentScale = 0;
	m_active = false;
	help.reset();
}

void OptionsMenu::update()
{
	if (m_active)
	{
		if (!helpPressed)
		{
			if (m_scalingIn)
			{
				scaleIn();
			}
			if (m_scalingOut)
			{
				scaleOut();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::End))
			{
				endAnimation();
			}
			mouseInput();
			keyboardInput();
		}
		else
		{
			if (help.returnToMenu())
			{
				helpPressed = false;
			}
			else
			{
				help.update();
			}
		}
	}
}

void OptionsMenu::render(sf::RenderWindow & m_window)
{
	if (m_active)
	{
		m_window.draw(m_backgroundSprite);
		m_window.draw(m_button);
		if (helpPressed)
		{
			help.render(m_window);
		}
	}
}