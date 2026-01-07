#include "Snake.h"

using namespace sf;

const float GRID_SIZE = 20.f;

Snake::Snake()
{
	// Settings for Movements:
	moveInterval = 0.1f;
	moveTimer = 0.f;
	
	// direction = { GRID_SIZE, 0.f };
	direction = { 0.f, 0.f };

	// body of the snake:
	sf::RectangleShape head(sf::Vector2f(GRID_SIZE, GRID_SIZE));
	head.setPosition({ 400.f, 300.f }); // Start position
	head.setFillColor(sf::Color::Green); // snake color
	body.push_back(head); // add to the body head

}
void Snake::handleInput()
{
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && direction.y == 0) {
		if (direction.y == 0) direction = { 0.f, -GRID_SIZE };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && direction.y == 0) {
		if (direction.y == 0) direction = { 0.f, GRID_SIZE };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && direction.x == 0) {
		if (direction.x == 0) direction = { -GRID_SIZE, 0.f };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && direction.x == 0) {
		if (direction.x == 0) direction = { GRID_SIZE, 0.f };
	}
}

void Snake::update() {
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	moveTimer += dt;

	if (moveTimer >= moveInterval) {

		// check moving dierction
		sf::Vector2f currentPos = body[0].getPosition();
		sf::Vector2f nextPos = currentPos + direction;
		
		bool collisionX = (nextPos.x < 0 || nextPos.x > 1270 - GRID_SIZE);
		bool collisionY = (nextPos.y < 0 || nextPos.y > 720 - GRID_SIZE);

		if (collisionX || collisionY)
		{
			// stop if it hit the border
			direction = { 0.f, 0.f };
		}

		else
		{
			body[0].move(direction);
		}
		
		moveTimer = 0;
	}
}

// drawing function
void Snake::render(sf::RenderWindow& window) {
	for (auto& part : body) {
		window.draw(part);
	}
}