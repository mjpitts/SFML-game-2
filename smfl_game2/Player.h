#ifndef PLAYER_H
#define PLAYER_H

// SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	sf::RectangleShape shape;
	
	void initVars();
	void initShapes();

public:
	Player();
	virtual ~Player();

	void update();
	void render(sf::RenderTarget* target);
};

#endif

