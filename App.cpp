#include "App.h"
#include <iostream>

void App::update(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    for (Button& button : keyBoards)
    {
        button.update(mousePos, sf::Mouse::isButtonPressed(sf::Mouse::Left));
    }
}


void App::run()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Button App");
    font.loadFromFile("arial.ttf");
    resultText.setFillColor(sf::Color::Red);
    resultText.setFont(font);

    for (int row = 0; row < 4; ++row)
    {
        for (int i = 0; i < symbols[row].size(); ++i)
        {
            sf::Vector2f buttonPosition;
            if (row == 1&&i > 8) {

                    buttonPosition = sf::Vector2f(i * BUTTON_SIZE + BUTTON_SIZE*2 , row * BUTTON_SIZE + BUTTON_SIZE);
                

            }
            else if (row == 2 && i > 6) {
                buttonPosition = sf::Vector2f(i * BUTTON_SIZE + row * BUTTON_SIZE + BUTTON_SIZE*2, row * BUTTON_SIZE+ BUTTON_SIZE);
            }
            else if (row == 3&&i>0) {
                buttonPosition = sf::Vector2f(i * BUTTON_SIZE + row * BUTTON_SIZE + BUTTON_SIZE * 2+ BUTTON_SIZE, row * BUTTON_SIZE + BUTTON_SIZE);
            }

            else
                buttonPosition = sf::Vector2f(i * BUTTON_SIZE + row * BUTTON_SIZE, row * BUTTON_SIZE+ BUTTON_SIZE);
            if (row == 3 && i == 0) {
                Button button(symbols[row][i], sf::Color::Color(128, 128, 128, 255), sf::Color::White, sf::Vector2f(BUTTON_SIZE*4, BUTTON_SIZE), buttonPosition, font, resultText);
                keyBoards.push_back(button);
            }
            else {
                Button button(symbols[row][i], sf::Color::Color(128, 128, 128, 255), sf::Color::White, sf::Vector2f(BUTTON_SIZE, BUTTON_SIZE), buttonPosition, font, resultText);
                keyBoards.push_back(button);
            }
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        update(window);
        window.clear();

        for (Button& button : keyBoards)
        {
            button.render(window);
        }
        
        resultText.setPosition(window.getPosition().x - resultText.getGlobalBounds().width, BUTTON_SIZE/3-5);
        window.draw(resultText);
        window.display();
    }
}