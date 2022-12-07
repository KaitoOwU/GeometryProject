#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "AllData.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Xenophobia");
    Game* game = new Game(&window);
    sf::Mouse mouse = sf::Mouse();
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
                    game->pInputManager->PressKey(event, deltaTime);
                    game->pEnemyManager->SpawnEnemy(1);
                    break;
                case sf::Event::KeyReleased:
                    game->pInputManager->ReleaseKey(event, deltaTime);
                    game->pEnemyManager->SpawnEnemy(1);
                    break;
                case sf::Event::MouseButtonPressed:
                    game->pInputManager->PressKey(event, deltaTime);
                    game->ui->CheckClick(mouse.getPosition(window),
                        window, game);
                    break;
                default:
                    game->pInputManager->ReleaseKey(event, deltaTime);
                    break;
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        deltaTime = clock.restart().asSeconds();

        game->Update(deltaTime);

        window.clear();
        
        game->Display(window);

        window.display();
    }
    delete game;
}