#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "AllData.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "ChronoSpacer");
    // Initialise everything below
    Game* game = new Game();
    sf::Mouse mouse = sf::Mouse();
    sf::Clock clock;
    float deltaTime = 0.f;
    Player* pPlayer = new Player(25, 5000, { 400, 300 }, sf::Color::Red, &deltaTime);
    EnemyManager* pEnemyManager = new EnemyManager(window);
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
                    break;
                case sf::Event::MouseButtonPressed:
                    pEnemyManager->SpawnEnemy(1);   
                    pInputManager->PressKey(event);
                    game->ui->CheckClick(mouse.getPosition(window),
                        window, game);
                    break;
                default:
                    pInputManager->ReleaseKey(event);
                    break;
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        deltaTime = clock.restart().asSeconds();

        game->Update(deltaTime);


        pEnemyManager->TrackPlayer(pPlayer, deltaTime);

        window.clear();
        
        game->Display(window);

        window.draw(pPlayer->shape);
        pEnemyManager->DrawEnemy();
        window.display();
    }
    delete game;
}