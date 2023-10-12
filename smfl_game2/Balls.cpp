#include "Balls.h"

void Balls::initShape(const sf::RenderWindow& window) {

	//Default color 
	sf::Color color(sf::Color::Cyan);

	switch (this->type)
	{
	case DEFAULT:
		color = sf::Color::Blue;
		break;
	case DAMAGING:
		color = sf::Color::Red;
		break;
	case HEALING:
		color = sf::Color::Green;
		break;
	}
	// Randomize color and size.
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
	this->shape.setFillColor(color);

	// Define area where balls can spawn.
	unsigned xSpawningBounds = (window.getSize().x - this->shape.getGlobalBounds().width);
	unsigned ySpawningBounds = (window.getSize().y - this->shape.getGlobalBounds().height);

	// Randomize position within valid spawn area. 
	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(rand() % xSpawningBounds),
		static_cast<float>(rand() % ySpawningBounds)
		));
}

const int& Balls::getType() const {
	return this->type;
}

Balls::Balls(const sf::RenderWindow& window, int type) {
	this->type = type;
	this->initShape(window);
}

Balls::~Balls() {

}

const sf::CircleShape& Balls::getShape() const {
	return this->shape;
}

void Balls::update() {

}

void Balls::render(sf::RenderTarget& target) {
	target.draw(this->shape);
}
