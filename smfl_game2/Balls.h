#ifndef BALLS_H
#define BALLS_H

// SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Balls
{
private:
	sf::CircleShape shape;

	void initShape();


public:
	Balls();
	virtual ~Balls();

	// Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif
