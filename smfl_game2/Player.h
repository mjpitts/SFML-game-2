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

	// Variables
	float ms;
	const int MAXHP = 3;
	int hp;
	
	void initVars();
	void initShapes();

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();
	
	// Accessors 
	const sf::RectangleShape& getShape() const; 
	const int& getHp() const;
	const int& getHpMax() const;

	// Functions
	void takeDamage(const int damage);
	void gainHealth(const int health);

	void updateInput();
	void updateWinCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

#endif

