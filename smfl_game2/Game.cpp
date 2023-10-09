#include "Game.h"

Game::Game() {

	this->initVars();
	this->initWindow();

}

Game::~Game() {
	delete this->window;
}

void Game::update()
{
}

void Game::render()
{
}

void Game::initVars() {
	this->endGame = false;
}

void Game::initWindow() {
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
}
