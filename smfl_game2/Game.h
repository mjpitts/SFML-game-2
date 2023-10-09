#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>

// SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Game {
public:

	// Construct / Destruct
	Game();
	~Game();

	// Accessors

	// Modifiers

	// Functions
	void update();
	void render();

private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;

	void initVars();
	void initWindow();
};

#endif

