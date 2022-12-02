#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
    // Initialise everything below
    sf::Clock clock;
    float deltaTime = 0;
    Player* pPlayer = new Player(25, 5000, {400, 300}, sf::Color::Red, &deltaTime);
    InputManager* pInputManager = new InputManager(pPlayer);
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
        window.display();
    }
}