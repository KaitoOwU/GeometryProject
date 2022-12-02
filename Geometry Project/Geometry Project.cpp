#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "AllData.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "ChronoSpacer");
    // Initialise everything below
    Game* game = new Game();
    // Game loop
    std::cout << GetAppPath() << std::endl;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Process any input event here

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    Input(event);
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
        game->Display(window);
        window.display();
    }
}