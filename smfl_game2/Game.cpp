#include "Game.h"

Game::Game() {

	this->initVars();
	this->initWindow();
	this->initFont();
	this->initText();

}

Game::~Game() {
	delete this->window;
}

const bool& Game::getEndGame() const {
	return this->endGame;
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

const int Game::randomizeType() {

	int type = BallTypes::DEFAULT;
	unsigned int raw = rand() % 100;

	if (raw <= 20) {
		type = BallTypes::HEALING;
	}
	if (raw >= 80) {
		type = BallTypes::DAMAGING;
	}

	return type;
}


// Functions
void Game::spawnBalls() {
	// Timer
	if (this->spawnTimer < this->spawnTimerMax) {
		this->spawnTimer += 1.f;
	}
	else {
		if (this->ballVec.size() < this->maxBalls) {
			this->ballVec.push_back(Balls(*this->window, this->randomizeType()));

			this->spawnTimer = 0.f;
		}
	}
}

void Game::updatePlayer() {
	this->player.update(this->window);

	if (this->player.getHp() <= 0) {
		this->endGame = true;
	}
}

void Game::updateCollison() {
	// Check if collision 
	for (int i = 0; i < this->ballVec.size(); i++) {
		if (this->player.getShape().getGlobalBounds().intersects(this->ballVec[i].getShape().getGlobalBounds())) {
			
			switch (this->ballVec[i].getType())
			{
			case BallTypes::DEFAULT:
				this->points++;
				break;
			case BallTypes::DAMAGING:
				this->player.takeDamage(1);
				break;
			case BallTypes::HEALING:
				this->player.gainHealth(1);
				break;
			}

			// Remove ball.
			this->ballVec.erase(this->ballVec.begin() + i);
		}
	}
}

void Game::update() {
	this->pollEvents();

	if (this->endGame == false) {
		this->spawnBalls();

		this->updatePlayer();

		this->updateCollison();

		this->updateGui();
	}
	
}

void Game::updateGui() {
	std::stringstream ss;
	ss << "Points: " << this->points << "\n"
		<< "Health: " << this->player.getHp() << "/" << this->player.getHpMax();

	this->guiText.setString(ss.str());
}

void Game::render() { 
	// Clear old window this display new.
	this->window->clear();

	//render stuff
	this->player.render(this->window);

	for (auto i : this->ballVec) {
		i.render(*this->window);
	}

	// Render gui
	this->renderGui(this->window);

	// Render end game
	if (this->endGame) {
		this->window->draw(this->endText);
	}

	// Show what has been rendered.
	this->window->display();
}

void Game::renderGui(sf::RenderTarget* target) {
	target->draw(this->guiText);
}

void Game::initVars() {
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBalls = 10;
	this->points = 0;
}

void Game::initWindow() {
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initFont() {
	if (!this->font.loadFromFile("./PixelifySans-Bold.ttf")) {
		std::cout << "ERROR::Game::initFont; could not load font!\n";
	}
}

void Game::initText() {
	// Game text
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(24);

	// End game text.
	this->endText.setFont(this->font);
	this->endText.setFillColor(sf::Color::White);
	this->endText.setCharacterSize(60);
	this->endText.setPosition(sf::Vector2f(250.f, 300.f));
	this->endText.setString("GAME OVER");

}
