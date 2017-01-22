#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Background.h"
#include "Planet.h"
#include "Player.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "Splash.h"
#include "FuelPickUp.h"
#include "XboxController.h"

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
		SplashScreen,
		MainMenu,
		Game,
		EndScreen
	};

	GameState currentGameState = GameState::Game;

private:
	sf::Texture m_backgroundTexture;
	Background m_background;

	sf::Texture m_planetTexture;
	std::vector<Planet> m_planets;
	Player m_player;
	GameOver m_gameOver;

	Splash m_splashScreen;
	MainMenu m_menu;

	sf::Texture m_fuelTexture;
	std::vector<FuelPickUp> fuelPickUpItems;
	XboxController xboxController;
};

#endif