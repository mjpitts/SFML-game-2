#include "Player.h"
#include <iostream>

void Player::initVars() {

}

void Player::initShapes() {
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x, float y) {

	this->shape.setPosition(x, y);

	this->initVars();
	this->initShapes();
}

Player::~Player() {

}

void Player::updateInput() {
	// Keyboard movement

	// Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->shape.move(-this->ms, 0.f);
	}
	// Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->shape.move(this->ms, 0.f);
	}
	// Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->shape.move(0, -this->ms);
	}
	// Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->shape.move(0, this->ms);
	}
}

void Player::updateWinCollision(const sf::RenderTarget* target) {

	sf::FloatRect playerPos = this->shape.getGlobalBounds();

	// Corrdinates after collision update
	float colX = playerPos.left;
	float colY = playerPos.top;

	// Left
	if (this->shape.getGlobalBounds().left <= 0.f) {
		colX = 0.f;
	}
	// Right
	else if(playerPos.left + playerPos.width >= target->getSize().x) {
		colX = target->getSize().x - playerPos.width;
	}
	// Top
	if (this->shape.getGlobalBounds().top <= 0.f) {
		colY = 0.f;
	}
	// Bottom
	else if (playerPos.top + playerPos.height >= target->getSize().y) {
		colY = target->getSize().y - playerPos.height;
	}

	this->shape.setPosition(colX, colY);
}

void Player::update(const sf::RenderTarget* target) {
	// Keyboard movement
	this->updateInput();

	// Window bounds collision
	this->updateWinCollision(target);
}

void Player::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
