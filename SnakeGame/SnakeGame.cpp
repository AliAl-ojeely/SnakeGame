#include <SFML/Graphics.hpp>
#include "Snake.h"

int main() {

    sf::RenderWindow window(sf::VideoMode({ 1270, 720 }), "Snake Game SFML 3.0");
    window.setFramerateLimit(60);

    Snake snake;

    while (window.isOpen()) {
    
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        snake.handleInput();
        snake.update();

        window.clear();
        snake.render(window);
        window.display();
    }

    return 0;
}