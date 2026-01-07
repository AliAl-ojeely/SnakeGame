#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Snake
{
public:

	Snake(); // Init function

	void handleInput();
	void update();
	void render(RenderWindow& window);

private:
	
	vector<RectangleShape> body;
	Vector2f direction;

	float moveTimer;
	float moveInterval;
};

