#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Background.h"
#include "Planet.h"
#include "Player.h"
#include "MainMenu.h"
//<<<<<<< HEAD
#include "GameOver.h"
//=======
#include "Splash.h"
//>>>>>>> 6fae90d91d56a7d87ff1d21669f4e077abd82079
#include "OptionsMenu.h"

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
//<<<<<<< HEAD
//	GameState currentGameState = GameState::Game;
//=======
//<<<<<<< HEAD
//	GameState currentGameState = GameState::EndScreen;
//=======
	GameState currentGameState = GameState::MainMenu;
//>>>>>>> 6fae90d91d56a7d87ff1d21669f4e077abd82079
//>>>>>>> 8fcecb1bcd273e03b167805e19068fa64b3a3c4c

private:
	sf::Texture m_backgroundTexture;
	Background m_background;

	sf::Texture m_planetTexture;
	std::vector<Planet> m_planets;
	Player m_player;
	GameOver m_gameOver;

	Splash m_splashScreen;
	MainMenu m_menu;
	OptionsMenu m_options;
	
};

#endif