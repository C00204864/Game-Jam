#include "HelpScreen.h"

HelpScreen::HelpScreen(std::string fileNameIn, float windowX, float windowY):
	m_returnToMenu(false)
{
	m_texture.loadFromFile(fileNameIn);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(sf::Vector2f(0, 0));
	m_sprite.setScale(windowX / m_sprite.getLocalBounds().width, windowY / m_sprite.getLocalBounds().height);
}

void HelpScreen::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::End))
	{
		m_returnToMenu = true;
	}
}

void HelpScreen::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

bool HelpScreen::returnToMenu()
{
	return m_returnToMenu;
}

void HelpScreen::reset()
{
	m_returnToMenu = false;
}