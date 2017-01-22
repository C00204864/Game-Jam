#include "Game.h"

#define MS_PER_UPDATE 10.0

Game::Game()
	: m_window(sf::VideoMode(1440, 900, 32), "Global Game Jam", sf::Style::Fullscreen),
		m_player(sf::Vector2f(400, 400), sf::Vector2f(0, 0), 0.0f, "Resources/Player/SpaceShip.png", m_window.getSize())
	, m_splashScreen("Resources/SplashScreen/SplashScreen.png", m_window.getSize().x, m_window.getSize().y)
{
	if (!m_planetTexture.loadFromFile("Resources/Planets/Planet_11.png"))
	{
		std::cout << "GAME:: Planet texture not loaded" << std::endl;
	}

	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(100.0f, 900.0f), 0.90f));
	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(600.0f, 1800.0f), 2.0f));
	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(900.0f, 50.0f), 0.5f));
	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(1000.0f, 140.0f), 2.0f));
	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(1500.0f, 1700.0f), 1.0f));
	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(1400.0f, 400.0f), 0.9f));
	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(2500.0f, 800.0f), 1.2f));
	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(3400.0f, 800.0f), 2.5f));
	m_planets.push_back(Planet(m_planetTexture, sf::Vector2f(3200.0f, 1500.0f), 1.0f));


	if (!m_fuelTexture.loadFromFile("Resources/Items/fuel.png"))
	{
		std::cout << "GAME:: Fuel item texture not loaded" << std::endl;
	}

	fuelPickUpItems.push_back(FuelPickUp(m_fuelTexture, sf::Vector2f(1400.0f, 400.0f)));
	fuelPickUpItems.push_back(FuelPickUp(m_fuelTexture, sf::Vector2f(1400.0f, 600.0f)));
	fuelPickUpItems.push_back(FuelPickUp(m_fuelTexture, sf::Vector2f(900.0f, 1400.0f)));
}

void Game::run()
{	
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	sf::Clock clock;
	timeSinceLastUpdate = clock.restart();

	while (m_window.isOpen())
	{
		processEvents();

		timeSinceLastUpdate += clock.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			update(timeSinceLastUpdate.asMilliseconds());
			timeSinceLastUpdate = sf::Time::Zero;
		}

		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

void Game::processGameEvents(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_window.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		m_player.reset();
	}

	switch (currentGameState)
	{
		case GameState::EndScreen:
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				m_gameOver.screenFadeIn();
			}

			
		}
	}
}

void Game::update(double dt)
{
	switch (currentGameState)
	{
		case GameState::SplashScreen:
		{
			m_splashScreen.update();

			if (m_splashScreen.animationComplete())
			{
				currentGameState = GameState::MainMenu;
			}

			break;
		}

		case GameState::MainMenu:
		{
			m_menu.update();
			if (m_menu.playPressed)
			{
				currentGameState = GameState::Game;
			}
			else if(m_menu.quitePressed)
			{
				m_window.close();
			}
			break;
		}
		case GameState::Game:
		{
			m_player.update(dt);

			int i = 0;
			for (std::vector<FuelPickUp>::iterator it = fuelPickUpItems.begin(); it != fuelPickUpItems.end(); it++)
			{
				it->update(m_player.getPosition());

				if (it->isCollided())
				{
					it->fuelPosition = sf::Vector2f();
				}

				i++;
			}

			for (std::vector<Planet>::iterator it = m_planets.begin(); it != m_planets.end(); it++)
			{
				m_player.checkGravity(it->GetPosition(), it->GetMass());
				
				if (m_player.playerState != Dead)
				{
					m_player.checkCollision(it->GetPosition(), it->GetSpriteWidth());
				}
			}

			for (std::vector<Planet>::iterator it = m_planets.begin(); it != m_planets.end(); it++)
			{
				// Do collision here
			}

			break;
		}
		case GameState::EndScreen:
		{
			if (m_gameOver.quitGame())
			{
				m_window.close();
			}
			m_gameOver.update();
			break;
		}

	default:
		break;
	}
}

void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));

	switch (currentGameState)
	{
		case GameState::SplashScreen:
		{
			m_splashScreen.render(m_window);
			break;
		}

		case GameState::MainMenu:
		{
			m_menu.render(m_window);
			break;
		}
		case GameState::Game:
		{
			m_background.render(m_window);

			for (std::vector<Planet>::iterator it = m_planets.begin(); it != m_planets.end(); it++)
			{
				it->render(m_window);
			}

			for (std::vector<FuelPickUp>::iterator it = fuelPickUpItems.begin(); it != fuelPickUpItems.end(); it++)
			{
				it->render(m_window);
			}

			m_player.render(m_window);
		
			break;
		}
		case GameState::EndScreen:
		{
			m_gameOver.render(m_window);
			break;
		}

		default:
			break;
	}

	m_window.display();
}