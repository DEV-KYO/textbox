//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_APPLICATION_H
#define TEXT_INPUT_PROJECT_APPLICATION_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "TextBox/LetterObject.h"


#include <iostream>

#include "TextBox/TextBox.h"

class Application {
    sf::RenderWindow window;
    TextBox textBox;

public:
    Application();
    void run();
    void draw();
    void processEvents();
    void update();
    void render();
};


#endif //TEXT_INPUT_PROJECT_APPLICATION_H
