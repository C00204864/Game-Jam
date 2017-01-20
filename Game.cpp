#include "Game.h"

#define MS_PER_UPDATE 10.0

Game::Game()
	: m_window(sf::VideoMode(1440, 900, 32), "Global Game Jam", sf::Style::Default)
{

}

void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

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
	switch (event.type)
	{
	case sf::Keyboard::Escape:
		m_window.close();
		break;
	default:
		break;
	}
}

void Game::update(double dt)
{
	switch (currentGameState)
	{
		case GameState::Game:
		{
			

			break;
		}

	default:
		break;
	}
}

void Game::render()
{
	m_window.clear(sf::Color(100, 0, 0, 0));

	switch (currentGameState)
	{
		case GameState::Game:
		{

		
			break;
		}

		default:
			break;
	}

	m_window.display();
}