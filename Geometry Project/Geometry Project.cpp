#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Enemy.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
    // Initialise everything below
    Enemy* enemy = new Enemy(50.0f, { 100, 100 }, sf::Color::Yellow, 100.0f, 1.0f, 1.0f, 10.0f);
    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Process any input event here

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    //...
                    break;
                default:
                    break;
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        // Whatever I want to draw goes here
        window.draw(enemy->shape);
        window.display();
    }
}