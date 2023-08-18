#include "Button.h"
#include <Windows.h> // ��� ������������� WinAPI
#include "Config.h"
#include <iostream>

Button::Button(char symbol, sf::Color color_f, sf::Color color_b, sf::Vector2f size, sf::Vector2f position, sf::Font& font, sf::Text& resultText)
    : symbol(symbol), color_f(color_f), color_b(color_b), font(font),resultText(resultText)
{
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color_b);
    rectangle.setOutlineThickness(2); // ������� �������
    rectangle.setOutlineColor(sf::Color::Blue); // ���� �������

    buttonText.setFont(font);
    buttonText.setCharacterSize(FONT_SIZE);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setString(sf::String(symbol));

    // ������������ ������ �� ������ ������
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    buttonText.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
}

void Button::render(sf::RenderWindow& window)
{
    window.draw(rectangle);
    window.draw(buttonText);
}



void Button::update(sf::Vector2i mousePos, bool isMouseButtonPressed)
{
    bool isMouseOver = rectangle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    
    if (isMouseOver)
    {
        if (isMouseButtonPressed && !hasBeenPressed) // ��������� �������� �� hasBeenPressed
        {
            hasBeenPressed = true; // ������������� ���� � true
            rectangle.setFillColor(sf::Color(80, 80, 80)); // ��������� ����� ��� �������
            if (buttonText.getString() == "<") {
                std::string str = resultText.getString();
                str.pop_back();
                resultText.setString(str);
            }
            else {

                resultText.setString(resultText.getString() + buttonText.getString());
            }
        }
        else if (!isMouseButtonPressed)
        {
            hasBeenPressed = false; // ���������� ���� ��� ���������� ������
            rectangle.setFillColor(color_b); // ����������� �������� �����
        }
    }
    else
    {
        hasBeenPressed = false; // ���������� ����, ���� ������ �� ��������
        rectangle.setFillColor(color_b); // ����������� �������� �����
    }
}