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
	const bool running() const;
	void pollEvents();

	void update();
	void render();

private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	void initVars();
	void initWindow();
};

#endif

