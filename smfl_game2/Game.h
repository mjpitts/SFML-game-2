#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

// Include player class, includes sfml includes as well.
#include "Player.h"
#include "Balls.h"

class Game {
public:

	// Construct / Destruct
	Game();
	~Game();

	// Accessors
	const bool& getEndGame() const;

	// Modifiers

	// Functions
	const bool running() const;
	void pollEvents();
	const int randomizeType();
	void spawnBalls();
	void updatePlayer();
	void updateCollison();
	void update();
	void updateGui();
	void render();
	void renderGui(sf::RenderTarget* target);

private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	unsigned points;

	sf::Font font;
	sf::Text guiText;
	sf::Text endText;

	std::vector<Balls> ballVec;
	float spawnTimerMax;
	float spawnTimer;
	unsigned maxBalls;

	void initVars();
	void initWindow();
	void initFont();
	void initText();

};

#endif

