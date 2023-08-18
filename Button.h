#pragma once

#include <SFML/Graphics.hpp>

class Button
{
private:
    char symbol;
    sf::Color color_f;
    sf::Color color_b;
    sf::RectangleShape rectangle;
    sf::Text buttonText; 
    sf::Font& font;
    sf::Text& resultText;
    bool hasBeenPressed = false;

public:
    Button(char symbol, sf::Color color_f, sf::Color color_b, sf::Vector2f size, sf::Vector2f position, sf::Font& font, sf::Text& resultText);
    void render(sf::RenderWindow& window);
    void update(sf::Vector2i mousePos, bool isMouseButtonPressed);
};