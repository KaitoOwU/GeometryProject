#pragma once
#include "SFML/Graphics.hpp"
#include <windows.h>


const sf::Vector2f WINDOW_SIZE = { 1000, 1000 };

std::string GetAppPath();

std::string GetAssetsPath();

std::string GetAssetsPath(std::string fileName);

sf::Vector2f Normalize(sf::Vector2f& vector);