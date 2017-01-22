#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Background.h"
#include "Planet.h"
#include "Player.h"
#include "MainMenu.h"
<<<<<<< HEAD
//<<<<<<< HEAD
#include "GameOver.h"
//=======
#include "Splash.h"
//>>>>>>> 6fae90d91d56a7d87ff1d21669f4e077abd82079
#include "OptionsMenu.h"
=======
#include "GameOver.h"
#include "Splash.h"
#include "FuelPickUp.h"
#include "Goal.h"
#include "XboxController.h"
>>>>>>> ae623a3019d28ed633659e028cfad85fe8ba0d48

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
	void checkGoalCollision(Player player, Goal goal);

	sf::RenderWindow m_window;

	enum class GameState
	{
		SplashScreen,
		MainMenu,
		Game,
		EndScreen
	};
<<<<<<< HEAD
//<<<<<<< HEAD
//	GameState currentGameState = GameState::Game;
//=======
//<<<<<<< HEAD
//	GameState currentGameState = GameState::EndScreen;
//=======
	GameState currentGameState = GameState::MainMenu;
//>>>>>>> 6fae90d91d56a7d87ff1d21669f4e077abd82079
//>>>>>>> 8fcecb1bcd273e03b167805e19068fa64b3a3c4c
=======

	GameState currentGameState = GameState::Game;
>>>>>>> ae623a3019d28ed633659e028cfad85fe8ba0d48

private:
	sf::Texture m_backgroundTexture;
	Background m_background;

	sf::Texture m_planetTexture;
	std::vector<Planet> m_planets;
	Player m_player;
	GameOver m_gameOver;

	Splash m_splashScreen;
	MainMenu m_menu;
<<<<<<< HEAD
	OptionsMenu m_options;
	
=======

	sf::Texture m_fuelTexture;
	std::vector<FuelPickUp> fuelPickUpItems;
	Goal m_goal;
	sf::Texture m_goalTexture;
	XboxController xboxController;
>>>>>>> ae623a3019d28ed633659e028cfad85fe8ba0d48
};

#endif