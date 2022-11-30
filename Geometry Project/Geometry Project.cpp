#include <iostream>
#include <SFML/Graphics.hpp>
#include "Maxime.h"
#include "Kevin.h"
#include "Tom.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
    // Initialise everything below
    InitializeKevin();
    InitializeMaxime();
    InitializeTom();
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
        DrawKevin();
        DrawTom();
        DrawMaxime();
        window.display();
    }

}