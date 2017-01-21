#include "Splash.h"

Splash::Splash(std::string fileName, float windowX, float windowY) :
	fadeState(FadeIn),
	m_animationComplete(false)
{
	m_texture.loadFromFile(fileName);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(sf::Vector2f(0, 0));
	m_color.r = m_sprite.getColor().r;
	m_color.g = m_sprite.getColor().g;
	m_color.b = m_sprite.getColor().b;
	m_color.a = 0;
	m_sprite.setColor(m_color); 
	m_sprite.setScale(sf::Vector2f(windowX / m_sprite.getLocalBounds().width, windowY / m_sprite.getLocalBounds().height));
}

void Splash::update()
{
	if (!m_animationComplete)
	{
		if (fadeState == FadeIn)
		{
			fadeIn();
		}
		else
		{
			fadeOut();
		}
		m_sprite.setColor(m_color);
	}
}

void Splash::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Splash::fadeIn()
{
	m_color.a += ALPHA_CHANGE;
	if (m_color.a == MAX_ALPHA)
	{
		fadeState = FadeOut;
	}
}

void Splash::fadeOut()
{
	m_color.a -= ALPHA_CHANGE;
	if (m_color.a == 0)
	{
		m_animationComplete = true;
	}
}

bool Splash::animationComplete()
{
	return m_animationComplete;
}