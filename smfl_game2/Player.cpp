#include "Player.h"

void Player::initVars() {

}

void Player::initShapes() {
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player() {
	this->initVars();
	this->initShapes();
}

Player::~Player()
{
}

void Player::update() {

}

void Player::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
