#ifndef BALLS_H
#define BALLS_H

// SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

// Using enum for ball types.
enum BallTypes {
	DEFAULT = 0, DAMAGING, HEALING, NUMTYPES
};

class Balls
{
private:
	sf::CircleShape shape;
	int type;

	void initShape(const sf::RenderWindow& window);

	

public:
	Balls(const sf::RenderWindow& window, int type);
	virtual ~Balls();

	// Accessors
	const int& getType() const;
	const sf::CircleShape& getShape() const;

	// Functions
	void update();
	void render(sf::RenderTarget& target);
};

#endif
