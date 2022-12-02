#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "AllData.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "ChronoSpacer");
    // Initialise everything below
    Game game = Game();
    sf::Clock clock;
    float deltaTime = 0.f;
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
        deltaTime = clock.restart().asSeconds();

        game.Update(deltaTime);

        window.clear();

        game.Display(window);

        window.display();
    }
}