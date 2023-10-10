#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <vector>

// Include player class, includes sfml includes as well.
#include "Player.h"
#include "Balls.h"

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

	void spawnBalls();
	void update();
	void render();

private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	std::vector<Balls> ballVec;
	float spawnTimerMax;
	float spawnTimer;
	unsigned maxBalls;

	void initVars();
	void initWindow();

};

#endif

