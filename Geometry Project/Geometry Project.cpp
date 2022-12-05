#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "AllData.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Xenophobia");
    // Initialise everything below
    Game* game = new Game();
    sf::Mouse mouse = sf::Mouse();
    sf::Clock clock;
    float deltaTime = 0;
    Player* pPlayer = new Player(25, 5000, {400, 300}, sf::Color::Red, &deltaTime, &window);
    InputManager* pInputManager = new InputManager(pPlayer);
    // Game loop
    while (window.isOpen()) {
        sf::Event event;

        pPlayer->shootCooldown -= deltaTime;

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
                case sf::Event::MouseButtonPressed:
                    game->ui->CheckClick(mouse.getPosition(window),
                        window, game);
                    break;
                default:
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
        pPlayer->Display(window);

        window.display();
    }
}