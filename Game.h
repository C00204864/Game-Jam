#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Background.h"
#include "Planet.h"
#include "Player.h"
#include "MainMenu.h"
#include "GameOver.h"

class Game
{
public:
	Game();
	void run();

	
protected:
	void update(double dt);
	void render();
	void processEvents();
	void processGameEvents(sf::Event&);

	sf::RenderWindow m_window;

	enum class GameState
	{
		MainMenu,
		Game,
		EndScreen
	};
	GameState currentGameState = GameState::EndScreen;

private:
	sf::Texture m_backgroundTexture;
	Background m_background;

	sf::Texture m_planetTexture;
	std::vector<Planet> m_planets;
	Player m_player;
	GameOver m_gameOver;

	MainMenu m_menu;
};

#endif