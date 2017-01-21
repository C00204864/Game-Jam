#include "FuelUI.h"

///Default constructor for the FuelUI object
///Initialises position and rectangle bar position
FuelUI::FuelUI()
{
	initialiseSprite();
}

///Initialises the FuelUI Object position based
///on input and rectangle position.
FuelUI::FuelUI(sf::Vector2f pos)
{
	m_pos = pos;
	loadTexture("Resources/Fuel_Gauge.png");
}

///Destructor for the fuel ui object
FuelUI::~FuelUI()
{
	std::cout << "Destructing FuelUI Object" << std::endl;
}

///returns UI position
sf::Vector2f FuelUI::getPosition()
{
	return m_pos;
}


///Loads the texture for the 
///m_texture object via a 
///passed in file path
void FuelUI::loadTexture(std::string path)
{
	if (!m_texture.loadFromFile(path))
	{
		std::string s("Error loading FuelUI Texture at " + path);
		throw std::exception(s.c_str());
	}
	initialiseSprite();
}

///Set the positon of the Object
void FuelUI::setPosition(sf::Vector2f &pos)
{
	m_pos = pos;
}


///Update the FuelUI object based on the players
///Fuel value (Still to do)
void FuelUI::update(float fuel)
{
	sf::Vector2f fuelVec(m_bar.getSize().x, (maxHeight / 100) * fuel);
	m_bar.setSize(fuelVec);
}

///Render The UI Object to the game screen
void FuelUI::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
	window.draw(m_bar);
}

///Sets the fuel ui object texture,
///position and the bar rect position and color
void FuelUI::initialiseSprite()
{
	m_sprite.setTexture(m_texture);
	/*m_sprite.setScale(0.25f, 0.25f);*/
	sf::Vector2f scale = m_sprite.getScale();
	m_sprite.setPosition(m_pos);

	sf::Vector2f offset(scale.x * 175.0f, scale.y * 195);

	m_bar.setSize(sf::Vector2f(scale.x * 135.0f, scale.y * 165.0f));

	maxHeight = m_bar.getSize().y;
	m_bar.setOrigin(m_bar.getSize() / 2.0f);
	m_bar.setPosition(m_sprite.getPosition() + offset);
	m_bar.setFillColor(sf::Color::Green);
	m_bar.setOutlineColor(sf::Color::Black);
	m_bar.setOutlineThickness(2.0f);
	m_bar.rotate(180);
}
