#include "Explosion.h"

Explosion::Explosion(std::string fileNameIn):
	m_spriteNumber(-1)
{
	int arrayCount = (sizeof(m_sprites) / sizeof(m_sprites[0]));
	m_texture.loadFromFile(fileNameIn);
	float xPos = 1;
	float yPos = 1;
	for (int i = 0; i < arrayCount; i++)
	{
		m_sprites[i].setTexture(m_texture);
		if (i == CELLS_OF_ARRAY / 2)
		{
			xPos = 1;
			yPos = 1 + READ_INCREMENT;
		}
		m_sprites[i].setTextureRect(sf::IntRect(xPos, yPos, TEXTURE_RECT_SIZE, TEXTURE_RECT_SIZE));
		m_sprites[i].setScale(sf::Vector2f(SCALE, SCALE));
		xPos += READ_INCREMENT;
	}
}

void Explosion::update()
{
	m_spriteNumber++;
}

void Explosion::render(sf::RenderWindow & window)
{
	if (m_spriteNumber < ((CELLS_OF_ARRAY - 1) * DURATION_OF_FRAMES))
	{
		window.draw(m_sprites[m_spriteNumber / DURATION_OF_FRAMES]);
	}
	else
	{
		m_active = false;
	}
}

void Explosion::setActive(sf::Vector2f positionIn)
{
	for (int i = 0; i < CELLS_OF_ARRAY; i++)
	{
		m_sprites[i].setPosition(positionIn);
		m_sprites[i].setOrigin(m_sprites[i].getLocalBounds().width / 2.f, m_sprites[i].getLocalBounds().height / 2.f);
	}
	m_active = true;
	m_spriteNumber = -1;
}

bool Explosion::getState()
{
	return m_active;
}