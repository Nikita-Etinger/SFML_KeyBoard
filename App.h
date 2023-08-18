#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.h"
#include "Button.h"
#include <string>

class App
{
private:
    std::vector<Button> keyBoards;
    const std::string symbols[4] = {
        "qwertyuiop<789",
        "asdfghjkl456",
        "zxcvbnm123",
        " .,"
    };
    sf::Font font;
    sf::Text resultText;
    

public:
    void update(sf::RenderWindow& window);
    void render();
    void run();
};

