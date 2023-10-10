#include "Balls.h"

void Balls::initShape(const sf::RenderWindow& window) {

	// Randomize color and size.
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
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

Balls::Balls(const sf::RenderWindow& window) {
	this->initShape(window);
}

Balls::~Balls() {

}

void Balls::update() {

}

void Balls::render(sf::RenderTarget& target) {
	target.draw(this->shape);
}
