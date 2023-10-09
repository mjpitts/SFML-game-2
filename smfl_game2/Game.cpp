#include "Game.h"

Game::Game() {

	this->initVars();
	this->initWindow();

}

Game::~Game() {
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents() {
	while (this->window->pollEvent(this->sfmlEvent)) {
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
			break;
		}
	}
}

void Game::update() {
	this->pollEvents();
}

void Game::render() { 
	// Clear old window this display new.
	this->window->clear();

	//render stuff


	// Show what has been rendered.
	this->window->display();
}

void Game::initVars() {
	this->endGame = false;
}

void Game::initWindow() {
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
}
