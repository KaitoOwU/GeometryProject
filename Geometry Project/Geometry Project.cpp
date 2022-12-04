#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
    // Initialise everything below
    sf::Clock clock;
    float deltaTime = 0;
    Player* pPlayer = new Player(25, 5000, { 400, 300 }, sf::Color::Red, &deltaTime);
    EnemyManager* pEnemyManager = new EnemyManager(window);
    InputManager* pInputManager = new InputManager(pPlayer);

    pEnemyManager->SpawnEnemy(300);
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
            default:
                pInputManager->ReleaseKey(event);
                break;
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        pEnemyManager->TrackPlayer(pPlayer, deltaTime);

        window.clear();
        window.draw(pPlayer->shape);
        pEnemyManager->DrawEnemy();
        window.display();
    }
}