#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>

// Include player class, includes sfml includes as well.
#include "Player.h"

class Game {
public:

	// Construct / Destruct
	Game();
	~Game();

	// Accessors

	// Modifiers

	// Functions
	const bool running() const;
	void pollEvents();

	void update();
	void render();

private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	void initVars();
	void initWindow();

};

#endif

