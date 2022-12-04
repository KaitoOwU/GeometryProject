#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "AllData.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Xenophobia");
    // Initialise everything below
    sf::Clock clock;
    float deltaTime = 0;
    Player* pPlayer = new Player(25, 5000, {400, 300}, sf::Color::Red, &deltaTime);
    InputManager* pInputManager = new InputManager(pPlayer);
    // Game loop
    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            // Process any input event here

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    pInputManager->PressKey(event);
                    break;
                case sf::Event::KeyReleased:
                    pInputManager->ReleaseKey(event);
                    break;
                default:
                    break;
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(pPlayer->shape);
        window.display();
    }
}